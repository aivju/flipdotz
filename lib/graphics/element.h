// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef FONT_ELEMENT_H_
#define FONT_ELEMENT_H_

#include <cstdint>

#include "display.h"

namespace aivju {

class Element {
  public:
    Element(uint8_t x, uint8_t y);
    virtual void setPosition(uint8_t x, uint8_t y) = 0;
    virtual void render(Display* display) const = 0;

  protected:
    uint8_t x_;
    uint8_t y_;
};
}  // namespace aivju

#endif  // FONT_ELEMENT_H_
