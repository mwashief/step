#!/usr/bin/env python3
"""AtCoder scaffolding script.

Usage:
    python3 atcoder.py             # prompts for problem id, creates file, opens VS Code
    python3 atcoder.py abc190_e    # defaults to .cpp, just prints the path (no editor)
    python3 atcoder.py abc190_e.rs # creates a .rs file instead
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

ROOT = Path(__file__).resolve().parent.parent


def main():
    args = sys.argv[1:]
    problem_id = args[0] if args else input().strip()

    file_type = ".cpp"
    if "." in problem_id:
        problem_id, ext = problem_id.rsplit(".", 1)
        file_type = "." + ext
        print(f"file extension is {file_type}")

    upper = problem_id.upper()

    # Leading letters -> contest series, e.g. "ABC"
    contest = ""
    i = 0
    while i < len(upper) and upper[i].isalpha():
        contest += upper[i]
        i += 1

    if not contest:
        print(f"{RED}Invalid contest!{RESET}")
        return

    contest_title_length = len(contest)
    temp = upper[i:]

    # Digits -> contest number, e.g. "190"
    j = 0
    while j < len(temp) and temp[j].isdigit():
        contest += temp[j]
        j += 1
    problem = temp[j:]  # expects the AtCoder-style "_A" suffix

    problem_id_lower = problem_id.lower()

    if len(contest) <= contest_title_length:
        print(f"{RED}Invalid contest!{RESET}")
        return
    if len(problem) <= 1:
        print(f"{RED}Problem no is not provided!{RESET}")
        return

    print(f"{GREEN}Contest: {contest} Problem: {problem[1:]}{RESET}")

    contest_dir = ROOT / "atcoder" / contest

    if contest_dir.is_dir():
        print(f"{BLUE}{contest} contest folder already exists.{RESET}")
    else:
        print(f"{YELLOW}{contest} contest folder does not exist.{RESET}")
        contest_dir.mkdir(parents=True, exist_ok=True)
        print(f"{CYAN}{contest} contest folder created.{RESET}")

    file_path = contest_dir / f"{problem_id_lower}{file_type}"

    if file_path.exists():
        print(f"{BLUE}{problem_id_lower}{file_type} already exists.{RESET}")
    else:
        file_path.touch()
        print(f"{CYAN}{problem_id_lower}{file_type} created.{RESET}")

        if file_type == ".rs":
            sync_script = Path(__file__).resolve().parent / "sync_bins.py"
            if sync_script.exists():
                subprocess.run([sys.executable, str(sync_script)], check=False)
                print(f"{CYAN}Run it with: cargo run --bin {problem_id_lower}{RESET}")

    if args:
        print(file_path)
        return

    cmd = ["cmd.exe", "/c", "code", str(file_path)] if platform.system() == "Windows" \
        else ["code", str(file_path)]
    subprocess.Popen(cmd)


if __name__ == "__main__":
    main()
