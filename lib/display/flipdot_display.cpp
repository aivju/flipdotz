// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "array_size.h"
#include "display.h"
#include "display_config.h"
#include <Arduino.h>

namespace aivju {
namespace {

// Adjusted pin assignments from LAWO ESP32 controller by nalx @ section77
static byte kPins[]{
    1,  //  [0] DATA
    21, //  [1] COLUMN_1
    19, //  [2] COLUMN_2
    23, //  [3] COLUMN_3
    18, //  [4] COLUMN_4
    5,  //  [5] COLUMN_5
    17, //  [6] ROW_1
    16, //  [7] ROW_2
    4,  //  [8] ROW_3
    22, //  [9] ROW_4
    2,  // [10] ENABLE_SET
    15, // [11] ENABLE_RESET
    13, // [12] MODULE_1
    12, // [13] MODULE_2
    14, // [14] MODULE_3
    27, // [15] MODULE_4
    26  // [16] MODULE_5
};

// clang-format off
const byte kModulePins[] = {kPins[12], kPins[13], kPins[14], kPins[15], kPins[16]};
const byte kColumnBitPins[] = {kPins[1], kPins[2], kPins[3], kPins[4], kPins[5]};
const byte kRowBitPins[] = {kPins[6], kPins[7], kPins[8], kPins[9]};
// clang-format on
const int kDelayHighPulsInUs = 750;
const int kDelayFlipPulsInUs = 100;
const int kPauseBetweenDotFlipsInMs = 2;

void SetRowAddress(byte row_idx) {
  for (auto bit = 0; bit < arraysize(kRowBitPins); bit++) {
    const auto value = bitRead(row_idx, bit) ? HIGH : LOW;
    digitalWrite(kRowBitPins[bit], value);
  }
}

void SetColumnAddress(byte col_idx) {
  for (auto bit = 0; bit < arraysize(kColumnBitPins); bit++) {
    const auto value = bitRead(col_idx, bit) ? HIGH : LOW;
    digitalWrite(kColumnBitPins[bit], value);
  }
}

void FlipDotAtModule(byte module_idx, boolean toggle) {
  digitalWrite(kPins[0], toggle ? HIGH : LOW);
  delayMicroseconds(kDelayFlipPulsInUs);
  digitalWrite(kModulePins[module_idx], HIGH);
  const auto set_pin = toggle ? kPins[10] : kPins[11];
  digitalWrite(set_pin, HIGH);
  delayMicroseconds(kDelayHighPulsInUs);
  digitalWrite(set_pin, LOW);
  digitalWrite(kModulePins[module_idx], LOW);
  delayMicroseconds(kDelayFlipPulsInUs);
}
} // namespace

FlipDotDisplay::FlipDotDisplay(byte width, byte height)
    : Display(width, height) {

  // Initialize GPIO pins and layout
  for (const byte pin : kPins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  delay(1000);
}

void FlipDotDisplay::setPixel(byte x, byte y, bool toggle) {
  byte module_index =
      (x < kModuleWidth * kNumModules) ? x / kModuleWidth : kNumModules;
  SetRowAddress(y);
  SetColumnAddress(x);
  FlipDotAtModule(module_index, toggle);
  delay(kPauseBetweenDotFlipsInMs);
}

void FlipDotDisplay::clear() {
  for (int x = 0; x < kDisplayWidth; x++) {
    for (int y = 0; y < kDisplayHeight; y++) {
      setPixel(x, y, false);
    }
  }
}

void FlipDotDisplay::fill() {
  for (int x = 0; x < kDisplayWidth; x++) {
    for (int y = 0; y < kDisplayHeight; y++) {
      setPixel(x, y, true);
    }
  }
}

} // namespace aivju