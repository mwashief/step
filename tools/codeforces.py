#!/usr/bin/env python3
"""Codeforces scaffolding script.

Usage:
    python3 codeforces.py            # prompts for problem id, creates file, opens VS Code
    python3 codeforces.py 2248B      # defaults to .cpp, just prints the path (no editor)
    python3 codeforces.py 2248B.rs   # creates a .rs file instead
"""
import platform
import subprocess
import sys
from pathlib import Path

RESET = "\033[0m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
CYAN = "\033[36m"

BUNDLE_SIZE = 250
ROOT = Path(__file__).resolve().parent.parent


def get_bundle(contest: int) -> str:
    bundle_number = (contest + BUNDLE_SIZE - 1) // BUNDLE_SIZE
    end = BUNDLE_SIZE * bundle_number
    start = end - BUNDLE_SIZE + 1
    return f"{start:04d}-{end:04d}"


def main():
    args = sys.argv[1:]
    problem_id = args[0] if args else input().strip()

    file_type = ".cpp"
    if "." in problem_id:
        problem_id, ext = problem_id.rsplit(".", 1)
        file_type = "." + ext
        print(f"file extension is {file_type}")

    problem_id = problem_id.upper()

    contest, problem = "", ""
    for i, ch in enumerate(problem_id):
        if ch.isdigit():
            contest += ch
        else:
            problem = problem_id[i:]
            break

    if not contest:
        print(f"{RED}Invalid contest!{RESET}")
        return
    if not problem:
        print(f"{RED}Problem no is not provided!{RESET}")
        return

    print(f"{GREEN}Contest: {contest} Problem: {problem}{RESET}")

    contest_dir = ROOT / "codeforces" / get_bundle(int(contest)) / contest

    if contest_dir.is_dir():
        print(f"{BLUE}{contest} contest folder already exists.{RESET}")
    else:
        print(f"{YELLOW}{contest} contest folder does not exist.{RESET}")
        contest_dir.mkdir(parents=True, exist_ok=True)
        print(f"{CYAN}{contest} contest folder created.{RESET}")

    file_path = contest_dir / f"{problem_id}{file_type}"

    if file_path.exists():
        print(f"{BLUE}{problem_id}{file_type} already exists.{RESET}")
    else:
        file_path.touch()
        print(f"{CYAN}{problem_id}{file_type} created.{RESET}")

        # Keep the rust-analyzer symlink farm in sync when a .rs file is created
        if file_type == ".rs":
            sync_script = Path(__file__).resolve().parent / "sync_bins.py"
            if sync_script.exists():
                subprocess.run([sys.executable, str(sync_script)], check=False)

    if args:
        # Matches the original: when called with an explicit arg, just print
        # the path and exit — useful for wrapping in a shell function.
        print(file_path)
        return

    cmd = ["cmd.exe", "/c", "code", str(file_path)] if platform.system() == "Windows" \
        else ["code", str(file_path)]
    subprocess.Popen(cmd)


if __name__ == "__main__":
    main()
