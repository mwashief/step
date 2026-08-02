#!/usr/bin/env python3
"""Compile and run a competitive-programming C++ file with strict,
sanitizer-enabled flags.

Usage:
    python3 cpp_compile.py path/to/file.cpp
"""
import platform
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
BLACK = "\033[30m"
GREEN_BG = "\033[42m"
RED_BG = "\033[41m"

ROOT = Path(__file__).resolve().parent.parent
BOOST_INCLUDE = "/home/emzie/boost/boost_1_83_0/"


def main():
    if len(sys.argv) < 2:
        return

    src = Path(sys.argv[1].strip('"'))
    if not src.is_absolute():
        src = (ROOT / src).resolve()

    is_windows = platform.system() == "Windows"
    exe_path = src.with_suffix(".exe" if is_windows else ".out")

    print(f"{PURPLE}OS: {RESET}{BLUE}{platform.system()}{RESET}")
    print(f"{PURPLE}Path: {RESET}{BLUE}{src}{RESET}")

    output_txt = ROOT / "IO" / "output.txt"
    input_txt = ROOT / "IO" / "input.txt"

    compile_cmd = [
        "g++", "-Wall", "-Wextra", "-pedantic", "-std=c++20",
        "-Wshadow", "-Wformat=2", "-Wfloat-equal", "-Wconversion",
        "-Wlogical-op", "-Wshift-overflow=2", "-Wduplicated-cond",
        "-Wcast-qual", "-Wcast-align",
        "-D_GLIBCXX_DEBUG", "-D_GLIBCXX_DEBUG_PEDANTIC", "-D_FORTIFY_SOURCE=2",
        "-fsanitize=address", "-fsanitize=undefined", "-fno-sanitize-recover",
        "-fstack-protector",
        f"-I{BOOST_INCLUDE}",
        f'-DLOCAL_OUTPUT="{output_txt}"',
        f'-DLOCAL_INPUT="{input_txt}"',
        str(src), "-o", str(exe_path),
    ]
    if is_windows:
        compile_cmd.insert(1, "-Wl,--stack,268435456")

    exe_path.unlink(missing_ok=True)

    subprocess.run(compile_cmd)
    print(f"{GREEN}\u2705{RESET}{YELLOW} Compilation process done{RESET}")

    if not exe_path.exists():
        print(f"{RED}\u274c Compilation unsuccessful{RESET}")
        return

    try:
        start = time.perf_counter()
        subprocess.run([str(exe_path)], check=True)
        elapsed_ms = (time.perf_counter() - start) * 1000
        print("\u2705 Execution done")
        bg, fg = (RED_BG, BLACK) if is_windows else (GREEN_BG, WHITE)
        print(f"{RED}-- Execution time: {bg}{fg}{elapsed_ms:.0f}ms{RESET}")
    except Exception:
        print(f"{RED}\u274c Compilation unsuccessful{RESET}")


if __name__ == "__main__":
    main()
