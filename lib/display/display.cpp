// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "display.h"

#include "display_config.h"

namespace aivju {

uint8_t GetModuleIndex(uint8_t module_idx) {
    if (module_idx == kNumModules) {
        return kColumnShortModule;
    } else {
        return 0;
    }
}

Display::Display(uint8_t width, uint8_t height) : width_(width), height_(height) {
    current_buffer = new bool*[width_];
    next_buffer = new bool*[width_];
    for (uint8_t idx = 0; idx < width_; idx++) {
        current_buffer[idx] = new bool[height_]{false};
        next_buffer[idx] = new bool[height_]{false};
    }
}

void Display::setPixel(uint8_t x, uint8_t y, bool toggle) {
    next_buffer[x][y] = toggle;
}

void Display::render() {
    for (uint8_t x = 0; x < width_; x++) {
        for (uint8_t y = 0; y < height_; y++) {
            if (current_buffer[x][y] != next_buffer[x][y]) {
                drawPixel(x, y, next_buffer[x][y]);
                current_buffer[x][y] = next_buffer[x][y];
            }
        }
    }
}

uint8_t Display::getWidth() const {
    return width_;
}

uint8_t Display::getHeight() const {
    return height_;
}

}  // namespace aivju
