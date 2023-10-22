// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef FONT_TEXT_SCROLLER_H_
#define FONT_TEXT_SCROLLER_H_

#include <cstdint>
#include <string>

#include "display.h"
#include "font.h"
#include "text_element.h"

namespace aivju {

enum class ScrollDirection { LEFT_RIGHT, RIGHT_LEFT, UP_DOWN, DOWN_UP };

class TextScroller {
  public:
    TextScroller(const std::string& text,
                 uint8_t x,
                 uint8_t y,
                 Font& font,
                 ScrollDirection direction);
    void update();
    void render(Display* display);

  private:
    TextElement text_;
    ScrollDirection direction_;
    uint8_t speed_{1};
    int offset_;
    uint8_t x_, y_;
};

}  // namespace aivju

#endif  // FONT_TEXT_SCROLLER_H_
