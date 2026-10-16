#!/usr/bin/env python3
"""
Regenerate recomp_funcs/ with N64Recomp, stubbing any function it cannot
recompile, then post-process the output (fix_zero_reg_loads.py, fix_overlay_relocs.py,
fix_missing_overlay_relocs.py - the last needs the ROM at data/yoshis_story.z64).

N64Recomp stops at the first function it fails on ("Error recompiling X",
e.g. an INVALID instruction in bytes splat labelled as a function) and leaves
recomp_funcs/ half-written. This loop adds X to [patches] stubs in config.toml
and re-runs until N64Recomp succeeds, so N64Recomp itself decides what it
can't handle (tools/find_invalid_funcs.py only approximates that).

Usage (inside nix-shell tools/recomp-shell.nix):
  python3 tools/regen.py [--n64recomp build-n64recomp/N64Recomp] [--max-stubs 50]
"""

import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from find_invalid_funcs import apply_stubs  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
FAILED = re.compile(r"^Error recompiling (\S+)$", re.M)


def clean_output(out_dir):
    for pattern in ("*.c", "*.h", "*.inl"):
        for f in out_dir.glob(pattern):
            f.unlink()


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--n64recomp", type=Path, default=ROOT / "build-n64recomp" / "N64Recomp")
    ap.add_argument("--config", type=Path, default=ROOT / "config.toml")
    ap.add_argument("--max-stubs", type=int, default=50)
    args = ap.parse_args()

    out_dir = ROOT / "recomp_funcs"
    added = []
    while True:
        clean_output(out_dir)
        proc = subprocess.run([str(args.n64recomp), str(args.config)], cwd=ROOT,
                              capture_output=True, text=True)
        output = proc.stdout + proc.stderr
        if proc.returncode == 0:
            break
        m = FAILED.search(output)
        if not m:
            sys.stdout.write(output)
            sys.exit(f"N64Recomp failed (exit {proc.returncode}) without naming a function; see output above")
        name = m.group(1)
        reason = next((l for l in output.splitlines() if l.startswith("Unhandled instruction")), "")
        if name in added:
            sys.exit(f"{name} still fails after being stubbed; stopping")
        if len(added) >= args.max_stubs:
            sys.exit(f"stubbed {len(added)} functions and N64Recomp still fails; stopping")
        print(f"stubbing {name}  ({reason or 'see N64Recomp output'})", flush=True)
        apply_stubs(args.config, [name],
                    comment="N64Recomp failed to recompile these (tools/regen.py).")
        added.append(name)

    warnings = [l for l in output.splitlines() if l.startswith("[WARN]")]
    count = next((l for l in output.splitlines() if l.startswith("Function count")), "")
    print(f"N64Recomp OK. {count}. {len(warnings)} warnings.")
    if added:
        print(f"added {len(added)} stubs to {args.config.name}: {', '.join(added)}")
    for fixer in ("fix_zero_reg_loads.py", "fix_overlay_relocs.py", "fix_missing_overlay_relocs.py"):
        subprocess.run([sys.executable, str(ROOT / "tools" / fixer), str(out_dir)], check=True)
    print(f"{len(list(out_dir.glob('funcs_*.c')))} funcs_*.c files")


if __name__ == "__main__":
    main()
