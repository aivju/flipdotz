// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef FONT_FONT_H_
#define FONT_FONT_H_

#include <cstdint>

namespace aivju {

struct Glyph {
    int offset;
    int bit_width;
    int bit_height;
    int advance;
    int x_offset;
    int y_offset;
};

struct FontDescriptor {
    const uint8_t* bitmap;
    const Glyph* glyphs;
    const int8_t* lookup;
};

class Font {
  public:
    explicit Font(const FontDescriptor& data);
    Font(const uint8_t* bitmap, const Glyph* glyph, const int8_t* lookup);
    const uint8_t* getCharData(char c) const;
    const Glyph& getCharGlyph(char c) const;
    uint8_t getCharWidth(char c) const;
    uint8_t getCharHeight(char c) const;
    uint8_t getCharAdvance(char c) const;

  private:
    const uint8_t* bitmap_;
    const Glyph* glyphs_;
    const int8_t* lookup_;
};

}  // namespace aivju

#endif  // FONT_FONT_H_
