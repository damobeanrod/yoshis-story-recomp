#!/usr/bin/env python3
"""
Post-process N64Recomp output: drop relocation entries with an unknown type.

N64Recomp casts each ELF relocation type straight into its RelocType enum
(0..7: NONE, 16, 32, REL32, 26, HI16, LO16, GPREL16) and prints the name from
an 8-entry table. Relocations of a higher type in the decomp ELF (e.g.
R_MIPS_JALR hints the assembler attaches to `jalr`, target offset 0) index past
the table and come out as `.type =  }`, which does not compile.

These per-section reloc tables in recomp_overlays.inl are only used to relocate
mods/patches at runtime; code generation itself only consumes HI16/LO16/26/32.
Dropping the unknown-type entries is therefore safe.

Run after every N64Recomp invocation (tools/regen.py does this):
  tools/fix_overlay_relocs.py recomp_funcs
"""

import re
import sys
from pathlib import Path

UNKNOWN_TYPE = re.compile(r"^\s*\{ \.offset = 0x[0-9A-F]+, \.target_section_offset = 0x[0-9A-F]+, "
                          r"\.target_section = \d+, \.type = +\}, *\n", re.M)


def main():
    if len(sys.argv) != 2:
        sys.exit(f"usage: {sys.argv[0]} <recomp_funcs dir>")
    path = Path(sys.argv[1]) / "recomp_overlays.inl"
    text = path.read_text()
    new, n = UNKNOWN_TYPE.subn("", text)
    if n:
        path.write_text(new)
    print(f"dropped {n} unknown-type relocation(s) from {path.name}")


if __name__ == "__main__":
    main()
