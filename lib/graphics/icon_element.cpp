// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "icon_element.h"

#include <algorithm>

namespace aivju {

IconElement::IconElement(const uint16_t* data, uint8_t x, uint8_t y) : Element(x, y) {
    std::copy(data, data + 16, const_cast<uint16_t*>(data_));
}

void IconElement::setPosition(uint8_t x, uint8_t y) {
    x_ = x;
    y_ = y;
}

void IconElement::setData(const uint16_t* data) {
    std::copy(data, data + 16, data_);
}

void IconElement::render(Display* display) const {
    for (uint8_t row = 0; row < kHeight; ++row) {
        for (uint8_t col = 0; col < kWidth; ++col) {
            bool pixel = (data_[row] >> (kWidth - col)) & 0x01;
            display->drawPixel(x_ + col, y_ + row, pixel);
        }
    }
}

}  // namespace aivju