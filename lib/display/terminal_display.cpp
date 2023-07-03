// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "display.h"
#include <Arduino.h>
#include <cstdint>
#include <vector>

namespace aivju {
namespace {
std::vector<char> buffer;
}

TerminalDisplay::TerminalDisplay(byte width, byte height)
    : Display(width, height) {
  buffer.resize(width * height);
  for (int idx = 0; idx < buffer.size(); idx++) {
    buffer[idx] = 'O';
  }
}

void TerminalDisplay::setPixel(byte x, byte y, bool toggle) {
  buffer[y * width_ + x] = 'X';

  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      Serial.print(buffer[y * width_ + x]);
    }
    Serial.println();
  }
}

void TerminalDisplay::clear() {}

void TerminalDisplay::fill() {}

} // namespace aivju