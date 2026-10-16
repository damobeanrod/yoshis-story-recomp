#!/usr/bin/env python3
"""
Verify that a decomp ELF matches the retail ROM before recompiling it.

N64Recomp takes instructions and symbol addresses from the ELF, but at
runtime librecomp loads code-adjacent data (.data/.rodata, function
pointers, jump tables) from the user's ROM. If the ELF came from a
non-matching build, its layout drifts from the ROM and every address after
the first non-matching function is off — the recomp then reads the wrong
data and dispatches function pointers to the wrong (or no) function.

Two checks, both must pass:
  1. Every `func_XXXXXXXX` FUNC symbol sits at address XXXXXXXX.
  2. The ELF's .main section bytes are identical to the ROM at .main's
     ROM offset.

Exit status 0 on match, 1 on mismatch.

Usage:
  tools/check_elf_matches.py --elf ../yoshis-story-matching/build/yoshisstory-us.elf \
                             --rom ../yoshis-story-matching/baseroms/us/baserom.z64
"""

import argparse
import re
import struct
import sys
from pathlib import Path

GENERIC_NAME = re.compile(r"^func_([0-9A-Fa-f]{8})$")
STT_FUNC = 2
SHT_SYMTAB = 2


def parse_elf32_be(data):
    """Return (sections, symbols). sections: list of dicts; symbols: list of
    (name, value, size, type, shndx)."""
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 2:
        sys.exit("error: expected a 32-bit big-endian ELF")
    e_shoff, = struct.unpack_from(">I", data, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from(">HHH", data, 0x2E)

    sections = []
    for i in range(e_shnum):
        off = e_shoff + i * e_shentsize
        (name, typ, flags, addr, offset, size,
         link, info, align, entsize) = struct.unpack_from(">10I", data, off)
        sections.append(dict(name_off=name, type=typ, addr=addr, offset=offset,
                             size=size, link=link, entsize=entsize))

    def cstr(tab_off, idx):
        start = tab_off + idx
        return data[start:data.index(b"\0", start)].decode("ascii", "replace")

    shstr = sections[e_shstrndx]["offset"]
    for s in sections:
        s["name"] = cstr(shstr, s["name_off"])

    symbols = []
    for s in sections:
        if s["type"] != SHT_SYMTAB:
            continue
        strtab = sections[s["link"]]["offset"]
        for j in range(s["size"] // s["entsize"]):
            st_name, st_value, st_size, st_info, _, st_shndx = struct.unpack_from(
                ">IIIBBH", data, s["offset"] + j * s["entsize"])
            symbols.append((cstr(strtab, st_name), st_value, st_size,
                            st_info & 0xF, st_shndx))
    return sections, symbols


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--elf", required=True, type=Path)
    ap.add_argument("--rom", required=True, type=Path, help="retail big-endian .z64")
    ap.add_argument("--section", default=".main")
    ap.add_argument("--rom-offset", type=lambda x: int(x, 0), default=0x1070,
                    help="ROM offset of the section (default 0x1070, from yamls/us/main.yaml)")
    args = ap.parse_args()

    elf = args.elf.read_bytes()
    rom = args.rom.read_bytes()
    if rom[:4] != b"\x80\x37\x12\x40":
        sys.exit("error: ROM is not big-endian .z64 (byteswapped .v64/.n64?)")

    sections, symbols = parse_elf32_be(elf)
    ok = True

    # 1. Symbol-name check.
    bad = []
    for name, value, _, typ, _ in symbols:
        m = GENERIC_NAME.match(name)
        if typ == STT_FUNC and m and int(m.group(1), 16) != value:
            bad.append((name, value))
    print(f"symbol check: {len(bad)} func_XXXXXXXX symbols at the wrong address")
    for name, value in sorted(bad, key=lambda x: x[1])[:10]:
        print(f"  {name} is at 0x{value:08X} (delta {value - int(name[5:], 16):+#x})")
    ok &= not bad

    # 2. Byte check.
    sec = next((s for s in sections if s["name"] == args.section), None)
    if sec is None:
        sys.exit(f"error: no section named {args.section!r} in ELF")
    elf_bytes = elf[sec["offset"]:sec["offset"] + sec["size"]]
    rom_bytes = rom[args.rom_offset:args.rom_offset + sec["size"]]
    if elf_bytes == rom_bytes:
        print(f"byte check: {args.section} (0x{sec['size']:X} bytes @ 0x{sec['addr']:08X}) matches ROM")
    else:
        first = next(i for i in range(min(len(elf_bytes), len(rom_bytes)))
                     if elf_bytes[i] != rom_bytes[i]) if len(rom_bytes) else 0
        print(f"byte check: {args.section} DIFFERS from ROM, first at VRAM "
              f"0x{sec['addr'] + first:08X} (ROM 0x{args.rom_offset + first:X})")
        ok = False

    print("OK: ELF matches ROM" if ok else "FAIL: ELF does not match ROM — do not recompile from it")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
