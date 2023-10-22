// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "text_scroller.h"

namespace aivju {

TextScroller::TextScroller(const std::string& text,
                           uint8_t x,
                           uint8_t y,
                           Font& font,
                           ScrollDirection direction)
    : text_(text, x, y, font), direction_(direction), offset_(0), x_(x), y_(y) {}

void TextScroller::update() {
    switch (direction_) {
        case ScrollDirection::LEFT_RIGHT: offset_ -= speed_; break;
        case ScrollDirection::RIGHT_LEFT: offset_ += speed_; break;
        case ScrollDirection::UP_DOWN: offset_ -= speed_; break;
        case ScrollDirection::DOWN_UP: offset_ += speed_; break;
    }
}

void TextScroller::render(Display* display) {
    uint8_t render_x = x_;
    uint8_t render_y = y_;

    if (direction_ == ScrollDirection::LEFT_RIGHT || direction_ == ScrollDirection::RIGHT_LEFT) {
        render_x += offset_;
    } else {
        render_y += offset_;
    }

    text_.setPosition(render_x, render_y);
    text_.render(display);
}

}  // namespace aivju