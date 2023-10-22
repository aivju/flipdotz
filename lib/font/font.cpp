// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "font.h"

namespace aivju {

Font::Font(const FontDescriptor& data)
    : bitmap_(data.bitmap), glyphs_(data.glyphs), lookup_(data.lookup) {}

Font::Font(const uint8_t* bitmap, const Glyph* glyph, const int8_t* lookup)
    : bitmap_(bitmap), glyphs_(glyph), lookup_(lookup) {}

const uint8_t* Font::getCharData(char c) const {
    int index = lookup_[(int)c];
    if (index == -1)
        return nullptr;
    return &bitmap_[glyphs_[index].offset];
}

const Glyph& Font::getCharGlyph(char c) const {
    int index = lookup_[(int)c];
    return glyphs_[index];
}

uint8_t Font::getCharWidth(char c) const {
    return getCharGlyph(c).bit_width;
}

uint8_t Font::getCharHeight(char c) const {
    return getCharGlyph(c).bit_height;
}

uint8_t Font::getCharAdvance(char c) const {
    return getCharGlyph(c).advance;
}

}  // namespace aivju