// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "display.h"
#include <cstdint>
#include <iostream>
#include <vector>

namespace aivju {
namespace {
std::vector<char> buffer;
}

TerminalDisplay::TerminalDisplay(uint8_t width, uint8_t height)
    : Display(width, height) {
  buffer.resize(width * height);
  for (int idx = 0; idx < buffer.size(); idx++) {
    buffer[idx] = 'O';
  }
}

void TerminalDisplay::setPixel(uint8_t x, uint8_t y, bool toggle) {
  buffer[y * width_ + x] = 'X';

  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      std::cout << buffer[y * width_ + x];
    }
    std::cout << std::endl;
  }
  std::cout << "=========================" << std::endl;
}

void TerminalDisplay::clear() {}

void TerminalDisplay::fill() {}

} // namespace aivju