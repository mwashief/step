#!/usr/bin/env python3
"""Compile and run a competitive-programming Rust file via Cargo,
injecting LOCAL_INPUT/LOCAL_OUTPUT at compile time (Rust equivalent
of the C++ -DLOCAL_INPUT/-DLOCAL_OUTPUT flags).

Usage:
    python3 rust_compile.py path/to/file.rs
"""
import os
import platform
import re
import subprocess
import sys
import time
from pathlib import Path

RESET = "\033[0m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
PURPLE = "\033[35m"
WHITE = "\033[37m"
GREEN_BG = "\033[42m"

TOOLS_DIR = Path(__file__).resolve().parent
ROOT = TOOLS_DIR.parent
CARGO_TOML = ROOT / "Cargo.toml"


def find_bin_name(src: Path) -> str:
    """Look up the [[bin]] name Cargo knows this file by, from Cargo.toml."""
    rel_path = src.relative_to(ROOT).as_posix()
    content = CARGO_TOML.read_text()
    for block in re.findall(r"\[\[bin\]\](.*?)(?=\n\[\[bin\]\]|\Z)", content, re.DOTALL):
        name_match = re.search(r'name\s*=\s*"([^"]+)"', block)
        path_match = re.search(r'path\s*=\s*"([^"]+)"', block)
        if name_match and path_match and path_match.group(1) == rel_path:
            return name_match.group(1)
    raise SystemExit(f"No [[bin]] target found for {rel_path} — run sync_bins.py first.")


def main():
    if len(sys.argv) < 2:
        return

    src = Path(sys.argv[1].strip('"'))
    if not src.is_absolute():
        src = (ROOT / src).resolve()

    print(f"{PURPLE}Path: {RESET}{BLUE}{src}{RESET}")

    # Keep Cargo.toml's [[bin]] list current before building.
    subprocess.run([sys.executable, str(TOOLS_DIR / "sync_bins.py")], check=True)

    bin_name = find_bin_name(src)
    print(f"{PURPLE}Bin target: {RESET}{BLUE}{bin_name}{RESET}")

    # Inject absolute local IO paths at compile time — read in source via
    # env!("LOCAL_INPUT") / env!("LOCAL_OUTPUT"), same role as C++'s -D flags.
    build_env = {
        **os.environ,
        "LOCAL_INPUT": str(ROOT / "io" / "input.txt"),
        "LOCAL_OUTPUT": str(ROOT / "io" / "output.txt"),
    }

    build_cmd = ["cargo", "build", "--manifest-path", str(CARGO_TOML), "--bin", bin_name]
    result = subprocess.run(build_cmd, cwd=ROOT, env=build_env)
    print(f"{GREEN}\u2705{RESET}{YELLOW} Compilation process done{RESET}")

    if result.returncode != 0:
        print(f"{RED}\u274c Compilation unsuccessful{RESET}")
        return

    exe_name = bin_name + (".exe" if platform.system() == "Windows" else "")
    exe_path = ROOT / "target" / "debug" / exe_name

    try:
        start = time.perf_counter()
        subprocess.run([str(exe_path)], cwd=ROOT, check=True)
        elapsed_ms = (time.perf_counter() - start) * 1000
        print("\u2705 Execution done")
        print(f"{RED}-- Execution time: {GREEN_BG}{WHITE}{elapsed_ms:.0f}ms{RESET}")
    except Exception:
        print(f"{RED}\u274c Compilation unsuccessful{RESET}")


if __name__ == "__main__":
    main()
