// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "text_element.h"

#include "text_renderer.h"

namespace aivju {

TextElement::TextElement(const std::string& text, uint8_t x, uint8_t y, Font& font)
    : text_(text), x_(x), y_(y), font_(font) {}

void TextElement::setText(const std::string& text) {
    text_ = text;
}

void TextElement::setPosition(uint8_t x, uint8_t y) {
    x_ = x;
    y_ = y;
}

void TextElement::render(Display* display) {
    TextRenderer renderer(display, font_);
    renderer.renderText(x_, y_, text_);
}

}  // namespace aivju