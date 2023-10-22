#!/usr/bin/env python3
# Copyright(c) 2023 aivju GmbH
# All rights reserved.Redistribution and use in source and binary forms,
# with or without modification, are not permitted

"""Parse PNG file and create hex array from image data"""

from argparse import ArgumentParser, RawDescriptionHelpFormatter as rdhf
from cv2 import imread, IMREAD_UNCHANGED
from os.path import basename
from sys import exit


def to_hex_array(binary_string, name, width=16):
    rows = [binary_string[i:i + width] for i in range(0, len(binary_string), width)]
    hex_values = [hex(int(row, 2)) for row in rows]
    cpp_array = ",\n".join(hex_values)
    return f"const uint16_t k{name}Icon[] = {{\n{cpp_array}\n}};"


def main(args):
    img = imread(args.image, IMREAD_UNCHANGED)
    height, width, shape = img.shape
    assert width, height == (16, 16)
    binary_str = ""
    for y in range(height):
        for x in range(width):
            b, g, r, a = img[y, x]
            binary_str += str(int(a == 255))

    name = basename(args.image).split('.')[0]
    print(to_hex_array(binary_str, name))


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__, formatter_class=rdhf)
    parser.add_argument("image", help="Input image file")
    exit(main(parser.parse_args()))
