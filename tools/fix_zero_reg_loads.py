#!/usr/bin/env python3
"""
Post-process N64Recomp output: rewrite loads into $zero.

IDO emits `lw $zero, off(base)` for reads whose result is discarded (e.g.
volatile reads). N64Recomp renders the destination register as the literal
`0`, producing `0 = MEM_W(base, off);`, which is not valid C. Rewrite those to
`(void)(MEM_W(base, off));` so the memory access is kept and the result
dropped, matching hardware.

Run after every N64Recomp invocation:
  tools/fix_zero_reg_loads.py recomp_funcs
"""

import re
import sys
from pathlib import Path

ZERO_ASSIGN = re.compile(r"^(\s*)0 = (.+);$", re.M)


def main():
    if len(sys.argv) != 2:
        sys.exit(f"usage: {sys.argv[0]} <recomp_funcs dir>")
    total = 0
    for path in sorted(Path(sys.argv[1]).glob("*.c")):
        text = path.read_text()
        new, n = ZERO_ASSIGN.subn(r"\1(void)(\2);", text)
        if n:
            path.write_text(new)
            print(f"{path.name}: {n}")
            total += n
    print(f"rewrote {total} load(s) into $zero")


if __name__ == "__main__":
    main()
