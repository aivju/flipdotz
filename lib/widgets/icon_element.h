// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef WIDGETS_ICON_ELEMENT_H_
#define WIDGETS_ICON_ELEMENT_H_

#include <cstdint>

#include "display.h"

namespace aivju {

class IconElement {
  public:
    static const uint8_t kWidth = 16;
    static const uint8_t kHeight = 16;

    IconElement(const uint16_t* data, uint8_t x, uint8_t y);
    void setPosition(uint8_t x, uint8_t y);
    void render(Display* display);

  private:
    const uint16_t* data_;
    uint8_t x_, y_;
};

}  // namespace aivju

#endif  // WIDGETS_ICON_ELEMENT_H_
