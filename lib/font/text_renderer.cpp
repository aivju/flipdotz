// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "text_renderer.h"

namespace aivju {

TextRenderer::TextRenderer(Display* display, Font& font) : display_(display), font_(font) {}

void TextRenderer::clearArea(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    for (uint8_t i = x; i < x + width; ++i) {
        for (uint8_t j = y; j < y + height; ++j) {
            display_->setPixel(i, j, false);
        }
    }
}

void TextRenderer::renderText(uint8_t x, uint8_t y, const std::string& text) {
    // Calculate the width and height of the text for clearing
    // that specific area to avoid overdrawing
    uint8_t text_width = 0;
    uint8_t text_height = 0;

    for (char c : text) {
        if (c == ' ') {
            text_width += 1;
        } else {
            const auto& glyph = font_.getCharGlyph(c);
            text_width += glyph.advance;
            if (glyph.bit_height > text_height) {
                text_height = glyph.bit_height;
            }
        }
    }
    clearArea(x, y, text_width, text_height);

    for (char c : text) {
        const uint8_t* data = font_.getCharData(c);
        const Glyph& glyph = font_.getCharGlyph(c);

        if (!data || glyph.offset == -1) {
            x += (c == ' ') ? 1 : glyph.advance;
            continue;
        }

        for (int row = 0; row < glyph.bit_height; ++row) {
            for (int col = 0; col < glyph.bit_width; ++col) {
                bool pixel = (data[row] >> (7 - col)) & 0x01;
                display_->setPixel(x + col + glyph.x_offset, y + row + glyph.y_offset, pixel);
            }
        }

        x += glyph.advance;
    }
}

}  // namespace aivju