#!/usr/bin/env python3
# Copyright(c) 2023 aivju GmbH
# All rights reserved.Redistribution and use in source and binary forms,
# with or without modification, are not permitted

"""Extract font metrics from BDF file"""

from argparse import ArgumentParser, RawDescriptionHelpFormatter as rdhf
from dataclasses import dataclass, field
from datetime import datetime as dt
from logging import basicConfig, info, INFO
from sys import exit
from typing import List

HEADER = f'''// Copyright (c) {dt.now().year} aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <cstdint>
#include "font.h"

'''


@dataclass
class Glyph:
    """A single glyph or letter such as '!' or 'a'"""
    name: str = ""
    bb_x: int = 0
    bb_y: int = 0
    bb_offx: int = 0
    bb_offy: int = 0
    encoding: int = 0
    offset: int = -1
    rows: List[int] = field(default_factory=list)
    width: int = 0
    height: int = 0
    advance: int = 0
    xoff: int = 0
    yoff: int = 0


def bytes(integer):
    return divmod(integer, 0x100)


def main(args):
    processing = False
    row_parsing = False
    bitmap = list()
    chars = list()

    with open(args.bdf) as infile:
        for line in infile.readlines():
            if 'FONT ' in line:
                font_name = "".join(line.split('-')[2:4])
            if 'STARTCHAR' in line:
                processing = True
                g = Glyph(name=line.split()[1])
            elif 'ENDCHAR' in line:
                g.height = len(bitmap)
                for value in bitmap:
                    high, low = bytes(value)
                    g.rows.append(high)
                chars.append(g)

                processing = False
                row_parsing = False
                bitmap.clear()

            if processing:
                if 'ENCODING' in line:
                    g.encoding = int(line.split()[1])
                if 'DWIDTH' in line:
                    g.width = int(line.split()[1])
                elif 'BBX' in line:
                    _, g.height, g.xoff, g.yoff = map(int, line.split()[1:])
                    g.advance = g.width + 1
                elif 'BITMAP' in line:
                    row_parsing = True
                elif row_parsing:
                    bitmap.append(int(line.rstrip().ljust(4, '0'), 16))

    chars.sort(key=lambda char: char.encoding)
    lookup = [-1] * 128
    for i, char in enumerate(chars):
        lookup[char.encoding] = i

    print(HEADER)
    print("const int8_t %sLookup[128] = {" % font_name)
    for i in range(0, 128, 8):
        print("\t", end='')
        for j in range(8):
            print("%d," % lookup[i + j], end='')
        print()
    print('};\n\n')

    print("const uint8_t %sBitmap[] = {" % font_name)
    idx = 0
    for char in chars:
        char.offset = idx
        if char.rows:
            print('\t', end='')
            for row in char.rows:
                print("0x%02X," % row, end='')
                idx += 1
            print("\t/* 0x%02X %s '%s' */" % (char.encoding, char.name, chr(char.encoding)))
    print('};\n\n')

    print("const aivju::Glyph %sGlyph[] = {" % font_name)
    for char in chars:
        character = "No Bitmap defined"
        if char.rows:
            character = chr(char.encoding)

        #offset, bit_width, bit_height, advance cursor, x-offset, y-offset
        print(
            "\t{ %d, %d, %d, %d, %d, %d }, /* 0x%02X %s '%s' */" % (
            char.offset, char.width, char.height, char.advance, char.xoff, char.yoff, char.encoding,
            char.name, character
            )
        )

    print('};\n\n')

    print("const aivju::FontDescriptor %s = {" % font_name)
    print("%sBitmap," % font_name)
    print("%sGlyph," % font_name)
    print("%sLookup" % font_name)
    print("};\n\n")


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__, formatter_class=rdhf)
    parser.add_argument("bdf", help="BDF input file")
    basicConfig(format="%(levelname)s: %(message)s", level=INFO)
    exit(main(parser.parse_args()))
