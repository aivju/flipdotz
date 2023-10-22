// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef FONT_TEXT_RENDERER_H_
#define FONT_TEXT_RENDERER_H_

#include <cstdint>
#include <string>

#include "display.h"
#include "font.h"

namespace aivju {

class TextRenderer {
  public:
    TextRenderer(Display* display, Font& font);
    void clearArea(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
    void renderText(uint8_t x, uint8_t y, const std::string& text);

  private:
    Display* display_;
    Font& font_;
};

}  // namespace aivju

#endif  // FONT_TEXT_RENDERER_H_
