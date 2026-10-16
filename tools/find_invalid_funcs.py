#!/usr/bin/env python3
"""
List functions N64Recomp cannot recompile because they contain an instruction
that decodes as INVALID (usually non-code bytes that splat labelled as a
function), so they can be stubbed in one pass instead of one N64Recomp run each.

Function bounds match what N64Recomp uses: the ELF symbol size, overridden by
`function_sizes` in config.toml. Decoding uses rabbitizer, like N64Recomp (the
decomp's venv has it: ~/git/yoshis-story-matching/.venv/bin/python3).

Usage:
  ~/git/yoshis-story-matching/.venv/bin/python3 tools/find_invalid_funcs.py \
      --elf ~/git/yoshis-story-matching/build/yoshisstory-us.elf --config config.toml [--apply]
--apply adds the functions found to [patches] stubs in config.toml.
"""

import argparse
import re
import struct
import sys
import tomllib
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from check_elf_matches import parse_elf32_be, STT_FUNC  # noqa: E402

CODE_SECTION = re.compile(r"\.main|\.ovl_[0-9A-F]+")


def find_invalid(elf_path, config):
    import rabbitizer  # only needed here; regen.py imports apply_stubs without it

    elf = elf_path.read_bytes()
    sections, symbols = parse_elf32_be(elf)
    sizes = {e["name"]: e["size"] for e in config["input"].get("function_sizes", [])}
    stubs = set(config.get("patches", {}).get("stubs", []))

    bad = []
    for name, value, size, typ, shndx in symbols:
        if typ != STT_FUNC or name.startswith(".L") or shndx >= len(sections):
            continue
        sec = sections[shndx]
        if not CODE_SECTION.fullmatch(sec["name"]):
            continue
        size = sizes.get(name, size)
        if size == 0 or name in stubs:
            continue
        start = sec["offset"] + (value - sec["addr"])
        for i in range(0, size - 3, 4):
            word = struct.unpack_from(">I", elf, start + i)[0]
            instr = rabbitizer.Instruction(word, vram=value + i)
            if instr.uniqueId == rabbitizer.InstrId.cpu_INVALID:
                bad.append((name, value, value + i, word, sec["name"]))
                break
    return bad


def apply_stubs(config_path, names,
                comment="Contain INVALID instructions (tools/find_invalid_funcs.py)."):
    text = config_path.read_text()
    m = re.search(r"^stubs = \[(.*?)^\]", text, re.S | re.M)
    if not m:
        sys.exit("error: no multi-line `stubs = [ ... ]` block in config.toml")
    block = m.group(1).rstrip()
    marker = f"    # {comment}\n"
    addition = "\n" + ("" if marker in text else marker) + \
        "".join(f'    "{n}",\n' for n in names)
    new = text[:m.start(1)] + block + addition + text[m.end(1):]
    config_path.write_text(new)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--elf", required=True, type=Path)
    ap.add_argument("--config", required=True, type=Path)
    ap.add_argument("--apply", action="store_true", help="add them to [patches] stubs")
    args = ap.parse_args()

    config = tomllib.loads(args.config.read_text())
    bad = find_invalid(args.elf, config)
    print(f"{len(bad)} functions with INVALID instructions")
    for name, value, at, word, sec in sorted(bad, key=lambda b: b[1]):
        print(f"  {name:24s} {sec:14s} invalid word 0x{word:08X} at 0x{at:08X}")
    if args.apply and bad:
        apply_stubs(args.config, [b[0] for b in sorted(bad, key=lambda b: b[1])])
        print(f"added {len(bad)} stubs to {args.config}")


if __name__ == "__main__":
    main()
