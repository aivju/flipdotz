// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef FONT_TEXT_ELEMENT_H_
#define FONT_TEXT_ELEMENT_H_

#include <cstdint>
#include <string>

#include "display.h"
#include "element.h"
#include "font.h"

namespace aivju {

class TextElement : public Element {
  public:
    TextElement(const std::string& text, uint8_t x, uint8_t y, const Font& font);
    void setText(const std::string& text);
    void setPosition(uint8_t x, uint8_t y) override;

    void render(Display* display) const override;

  private:
    std::string text_;
    Font font_;
};

}  // namespace aivju

#endif  // FONT_TEXT_ELEMENT_H_
