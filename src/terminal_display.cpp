// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <iostream>
#include <thread>
#include <vector>

#include "display.h"

namespace aivju {
namespace {
std::vector<char> buffer;
}

TerminalDisplay::TerminalDisplay(uint8_t width, uint8_t height) : Display(width, height) {
    buffer.resize(width * height);
    for (int idx = 0; idx < buffer.size(); idx++) {
        buffer[idx] = ' ';
    }
}

void TerminalDisplay::drawPixel(uint8_t x, uint8_t y, bool toggle) {
    if (toggle) {
        buffer[y * width_ + x] = 'O';
    } else {
        buffer[y * width_ + x] = ' ';
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    show();
}

void TerminalDisplay::show() {
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            std::cout << buffer[y * width_ + x];
        }
        std::cout << std::endl;
    }
}

void TerminalDisplay::clear() {
    for (uint8_t x = 0; x < width_; ++x) {
        for (uint8_t y = 0; y < height_; ++y) {
            drawPixel(x, y, false);
        }
    }
}

void TerminalDisplay::clearArea(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    for (uint8_t i = x; i < x + width; ++i) {
        for (uint8_t j = y; j < y + height; ++j) {
            drawPixel(i, j, false);
        }
    }
}

void TerminalDisplay::fill() {
    for (uint8_t x = 0; x < width_; ++x) {
        for (uint8_t y = 0; y < height_; ++y) {
            drawPixel(x, y, true);
        }
    }
}

}  // namespace aivju