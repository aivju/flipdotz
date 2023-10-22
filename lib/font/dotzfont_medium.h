// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <cstdint>

#include "font.h"

const int8_t DotzFontMediumLookup[128] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  -1,
    -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, -1, -1, -1, -1, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, -1, -1, -1, -1, -1, -1, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
    62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, -1, -1, -1, -1, -1,
};

const uint8_t DotzFontMediumBitmap[] = {
    0x60, 0x60, 0x60, 0x60, 0x00, 0x60, 0x60, /* 0x21 char33 '!' */
    0xA0, 0xA0,                               /* 0x22 char34 '"' */
    0x50, 0xF8, 0x50, 0xF8, 0x50,             /* 0x23 char35 '#' */
    0x20, 0x78, 0xA0, 0x70, 0x28, 0xF0, 0x20, /* 0x24 char36 '$' */
    0xC8, 0xC8, 0x10, 0x20, 0x40, 0x98, 0x98, /* 0x25 char37 '%' */
    0x60, 0x90, 0x60, 0x98, 0x90, 0x90, 0x68, /* 0x26 char38 '&' */
    0x80, 0x80,                               /* 0x27 char39 ''' */
    0x20, 0x40, 0x80, 0x80, 0x80, 0x40, 0x20, /* 0x28 char40 '(' */
    0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, /* 0x29 char41 ')' */
    0xC0, 0xC0,                               /* 0x2A char42 '*' */
    0x70, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x70, /* 0x30 char48 '0' */
    0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, /* 0x31 char49 '1' */
    0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0xF8, /* 0x32 char50 '2' */
    0xF8, 0x10, 0x20, 0x10, 0x08, 0x88, 0x70, /* 0x33 char51 '3' */
    0x10, 0x30, 0x50, 0x90, 0xF8, 0x10, 0x10, /* 0x34 char52 '4' */
    0xF8, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70, /* 0x35 char53 '5' */
    0x30, 0x40, 0x80, 0xF0, 0x88, 0x88, 0x70, /* 0x36 char54 '6' */
    0xF8, 0x08, 0x10, 0x20, 0x20, 0x20, 0x20, /* 0x37 char55 '7' */
    0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, /* 0x38 char56 '8' */
    0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0x60, /* 0x39 char57 '9' */
    0x80, 0x00, 0x80,                         /* 0x3A char58 ':' */
    0x40, 0x40, 0x00, 0x40, 0x40, 0x80,       /* 0x3B char59 ';' */
    0x70, 0x88, 0xB8, 0xA8, 0xB8, 0x80, 0x78, /* 0x40 char64 '@' */
    0x70, 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, /* 0x41 char65 'A' */
    0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0, /* 0x42 char66 'B' */
    0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, /* 0x43 char67 'C' */
    0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF0, /* 0x44 char68 'D' */
    0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8, /* 0x45 char69 'E' */
    0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0x80, /* 0x46 char70 'F' */
    0x70, 0x88, 0x80, 0xB8, 0x88, 0x88, 0x78, /* 0x47 char71 'G' */
    0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, /* 0x48 char72 'H' */
    0xE0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0x49 char73 'I' */
    0x38, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60, /* 0x4A char74 'J' */
    0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88, /* 0x4B char75 'K' */
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xF8, /* 0x4C char76 'L' */
    0x88, 0xD8, 0xA8, 0x88, 0x88, 0x88, 0x88, /* 0x4D char77 'M' */
    0x88, 0xC8, 0xA8, 0xA8, 0xA8, 0x98, 0x88, /* 0x4E char78 'N' */
    0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0x4F char79 'O' */
    0xF0, 0x88, 0x88, 0x88, 0xF0, 0x80, 0x80, /* 0x50 char80 'P' */
    0x70, 0x88, 0x88, 0x88, 0xA8, 0x98, 0x78, /* 0x51 char81 'Q' */
    0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, /* 0x52 char82 'R' */
    0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, /* 0x53 char83 'S' */
    0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /* 0x54 char84 'T' */
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0x55 char85 'U' */
    0x88, 0x88, 0x88, 0x88, 0x88, 0x50, 0x20, /* 0x56 char86 'V' */
    0x88, 0x88, 0x88, 0x88, 0xA8, 0xA8, 0x50, /* 0x57 char87 'W' */
    0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, /* 0x58 char88 'X' */
    0x88, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, /* 0x59 char89 'Y' */
    0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, /* 0x5A char90 'Z' */
    0x70, 0x08, 0x78, 0x88, 0x78,             /* 0x61 char97 'a' */
    0x80, 0x80, 0xB0, 0xC8, 0x88, 0xC8, 0xB0, /* 0x62 char98 'b' */
    0x70, 0x88, 0x80, 0x88, 0x70,             /* 0x63 char99 'c' */
    0x08, 0x08, 0x68, 0x98, 0x88, 0x98, 0x68, /* 0x64 char100 'd' */
    0x70, 0x88, 0xF8, 0x80, 0x70,             /* 0x65 char101 'e' */
    0x30, 0x48, 0xE0, 0x40, 0x40, 0x40, 0x40, /* 0x66 char102 'f' */
    0x78, 0x88, 0x78, 0x08, 0x70,             /* 0x67 char103 'g' */
    0x80, 0x80, 0xF0, 0x88, 0x88, 0x88, 0x88, /* 0x68 char104 'h' */
    0x40, 0x00, 0xC0, 0x40, 0x40, 0x40, 0xE0, /* 0x69 char105 'i' */
    0x10, 0x00, 0x30, 0x10, 0x10, 0x90, 0x60, /* 0x6A char106 'j' */
    0x80, 0x80, 0x88, 0x90, 0xE0, 0x90, 0x88, /* 0x6B char107 'k' */
    0xC0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0x6C char108 'l' */
    0xF0, 0xA8, 0xA8, 0xA8, 0xA8,             /* 0x6D char109 'm' */
    0xB0, 0xC8, 0x88, 0x88, 0x88,             /* 0x6E char110 'n' */
    0x70, 0x88, 0x88, 0x88, 0x70,             /* 0x6F char111 'o' */
    0xF0, 0x88, 0x88, 0xF0, 0x80,             /* 0x70 char112 'p' */
    0x78, 0x88, 0x88, 0x78, 0x08,             /* 0x71 char113 'q' */
    0xB0, 0xC8, 0x80, 0x80, 0x80,             /* 0x72 char114 'r' */
    0x70, 0x80, 0x70, 0x08, 0xF0,             /* 0x73 char115 's' */
    0x40, 0xE0, 0x40, 0x48, 0x30,             /* 0x74 char116 't' */
    0x88, 0x88, 0x88, 0x98, 0x68,             /* 0x75 char117 'u' */
    0x88, 0x88, 0x88, 0x50, 0x20,             /* 0x76 char118 'v' */
    0x88, 0x88, 0xA8, 0xA8, 0x50,             /* 0x77 char119 'w' */
    0x88, 0x50, 0x20, 0x50, 0x88,             /* 0x78 char120 'x' */
    0x88, 0x50, 0x20, 0x20, 0x40,             /* 0x79 char121 'y' */
    0xF8, 0x10, 0x20, 0x40, 0xF8,             /* 0x7A char122 'z' */
};

const aivju::Glyph DotzFontMediumGlyph[] = {
    {  0, 3, 7, 4, -1, 0}, /* 0x21 char33 '!' */
    {  7, 3, 2, 4,  0, 5}, /* 0x22 char34 '"' */
    {  9, 5, 5, 6,  0, 0}, /* 0x23 char35 '#' */
    { 14, 5, 7, 6,  0, 0}, /* 0x24 char36 '$' */
    { 21, 5, 7, 6,  0, 0}, /* 0x25 char37 '%' */
    { 28, 5, 7, 6,  0, 0}, /* 0x26 char38 '&' */
    { 35, 1, 2, 2,  0, 5}, /* 0x27 char39 ''' */
    { 37, 3, 7, 4,  0, 0}, /* 0x28 char40 '(' */
    { 44, 3, 7, 4,  0, 0}, /* 0x29 char41 ')' */
    { 51, 2, 2, 3,  0, 0}, /* 0x2A char42 '*' */
    { 53, 5, 7, 6,  0, 0}, /* 0x30 char48 '0' */
    { 60, 4, 7, 5, -1, 0}, /* 0x31 char49 '1' */
    { 67, 5, 7, 6,  0, 0}, /* 0x32 char50 '2' */
    { 74, 5, 7, 6,  0, 0}, /* 0x33 char51 '3' */
    { 81, 5, 7, 6,  0, 0}, /* 0x34 char52 '4' */
    { 88, 5, 7, 6,  0, 0}, /* 0x35 char53 '5' */
    { 95, 5, 7, 6,  0, 0}, /* 0x36 char54 '6' */
    {102, 5, 7, 6,  0, 0}, /* 0x37 char55 '7' */
    {109, 5, 7, 6,  0, 0}, /* 0x38 char56 '8' */
    {116, 5, 7, 6,  0, 0}, /* 0x39 char57 '9' */
    {123, 1, 3, 2,  0, 2}, /* 0x3A char58 ':' */
    {126, 2, 6, 3,  0, 0}, /* 0x3B char59 ';' */
    {132, 5, 7, 6,  0, 0}, /* 0x40 char64 '@' */
    {139, 5, 7, 6,  0, 0}, /* 0x41 char65 'A' */
    {146, 5, 7, 6,  0, 0}, /* 0x42 char66 'B' */
    {153, 5, 7, 6,  0, 0}, /* 0x43 char67 'C' */
    {160, 5, 7, 6,  0, 0}, /* 0x44 char68 'D' */
    {167, 5, 7, 6,  0, 0}, /* 0x45 char69 'E' */
    {174, 5, 7, 6,  0, 0}, /* 0x46 char70 'F' */
    {181, 5, 7, 6,  0, 0}, /* 0x47 char71 'G' */
    {188, 5, 7, 6,  0, 0}, /* 0x48 char72 'H' */
    {195, 3, 7, 4,  0, 0}, /* 0x49 char73 'I' */
    {202, 5, 7, 6,  0, 0}, /* 0x4A char74 'J' */
    {209, 5, 7, 6,  0, 0}, /* 0x4B char75 'K' */
    {216, 5, 7, 6,  0, 0}, /* 0x4C char76 'L' */
    {223, 5, 7, 6,  0, 0}, /* 0x4D char77 'M' */
    {230, 5, 7, 6,  0, 0}, /* 0x4E char78 'N' */
    {237, 5, 7, 6,  0, 0}, /* 0x4F char79 'O' */
    {244, 5, 7, 6,  0, 0}, /* 0x50 char80 'P' */
    {251, 5, 7, 6,  0, 0}, /* 0x51 char81 'Q' */
    {258, 5, 7, 6,  0, 0}, /* 0x52 char82 'R' */
    {265, 5, 7, 6,  0, 0}, /* 0x53 char83 'S' */
    {272, 5, 7, 6,  0, 0}, /* 0x54 char84 'T' */
    {279, 5, 7, 6,  0, 0}, /* 0x55 char85 'U' */
    {286, 5, 7, 6,  0, 0}, /* 0x56 char86 'V' */
    {293, 5, 7, 6,  0, 0}, /* 0x57 char87 'W' */
    {300, 5, 7, 6,  0, 0}, /* 0x58 char88 'X' */
    {307, 5, 7, 6,  0, 0}, /* 0x59 char89 'Y' */
    {314, 5, 7, 6,  0, 0}, /* 0x5A char90 'Z' */
    {321, 5, 5, 6,  0, 0}, /* 0x61 char97 'a' */
    {326, 5, 7, 6,  0, 0}, /* 0x62 char98 'b' */
    {333, 5, 5, 6,  0, 0}, /* 0x63 char99 'c' */
    {338, 5, 7, 6,  0, 0}, /* 0x64 char100 'd' */
    {345, 5, 5, 6,  0, 0}, /* 0x65 char101 'e' */
    {350, 5, 7, 6,  0, 0}, /* 0x66 char102 'f' */
    {357, 5, 5, 6,  0, 0}, /* 0x67 char103 'g' */
    {362, 5, 7, 6,  0, 0}, /* 0x68 char104 'h' */
    {369, 3, 7, 4,  0, 0}, /* 0x69 char105 'i' */
    {376, 4, 7, 5,  0, 0}, /* 0x6A char106 'j' */
    {383, 5, 7, 6,  0, 0}, /* 0x6B char107 'k' */
    {390, 3, 7, 4,  0, 0}, /* 0x6C char108 'l' */
    {397, 5, 5, 6,  0, 0}, /* 0x6D char109 'm' */
    {402, 5, 5, 6,  0, 0}, /* 0x6E char110 'n' */
    {407, 5, 5, 6,  0, 0}, /* 0x6F char111 'o' */
    {412, 5, 5, 6,  0, 0}, /* 0x70 char112 'p' */
    {417, 5, 5, 6,  0, 0}, /* 0x71 char113 'q' */
    {422, 5, 5, 6,  0, 0}, /* 0x72 char114 'r' */
    {427, 5, 5, 6,  0, 0}, /* 0x73 char115 's' */
    {432, 5, 5, 6,  0, 0}, /* 0x74 char116 't' */
    {437, 5, 5, 6,  0, 0}, /* 0x75 char117 'u' */
    {442, 5, 5, 6,  0, 0}, /* 0x76 char118 'v' */
    {447, 5, 5, 6,  0, 0}, /* 0x77 char119 'w' */
    {452, 5, 5, 6,  0, 0}, /* 0x78 char120 'x' */
    {457, 5, 5, 6,  0, 0}, /* 0x79 char121 'y' */
    {462, 5, 5, 6,  0, 0}, /* 0x7A char122 'z' */
};

const aivju::FontDescriptor DotzFontMedium = {DotzFontMediumBitmap, DotzFontMediumGlyph,
                                              DotzFontMediumLookup};
