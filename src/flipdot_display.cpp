// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <Arduino.h>

#include "array_size.h"
#include "config.h"
#include "display.h"
#include "display_config.h"

namespace aivju {
namespace {

void SetRowAddress(uint8_t row_idx) {
    for (auto bit = 0; bit < arraysize(kRowBitPins); bit++) {
        const auto value = bitRead(row_idx, bit) ? HIGH : LOW;
        digitalWrite(kRowBitPins[bit], value);
    }
}

void SetColumnAddress(uint8_t col_idx) {
    for (auto bit = 0; bit < arraysize(kColumnBitPins); bit++) {
        const auto value = bitRead(col_idx, bit) ? HIGH : LOW;
        digitalWrite(kColumnBitPins[bit], value);
    }
}

void FlipDotAtModule(uint8_t module_idx, boolean toggle) {
    if (toggle) {
        digitalWrite(kPins[0], HIGH);
        delayMicroseconds(kDelayFlipPulsInUs);
        digitalWrite(kModulePins[module_idx], HIGH);
        digitalWrite(kPins[10], HIGH);
        delayMicroseconds(kDelayHighPulsInUs);
        digitalWrite(kPins[10], LOW);
        digitalWrite(kModulePins[module_idx], LOW);
        delayMicroseconds(kDelayFlipPulsInUs);
    } else {
        digitalWrite(kPins[0], LOW);
        delayMicroseconds(kDelayFlipPulsInUs);
        digitalWrite(kModulePins[module_idx], HIGH);
        digitalWrite(kPins[11], HIGH);
        delayMicroseconds(kDelayHighPulsInUs);
        digitalWrite(kPins[11], LOW);
        digitalWrite(kModulePins[module_idx], LOW);
        delayMicroseconds(kDelayFlipPulsInUs);
    }
}

void FlipDot(uint8_t module_idx, byte row_idx, byte col_idx, bool toggle) {
    SetRowAddress(row_idx);
    SetColumnAddress(col_idx);
    FlipDotAtModule(module_idx, toggle);
    delay(kPauseBetweenDotFlipsInMs);
}

uint8_t GetStartColumn(uint8_t module_idx) {
    if (module_idx == kNumModules) {
        return kColumnShortModule;
    } else {
        return 0;
    }
}
}  // namespace

FlipDotDisplay::FlipDotDisplay(uint8_t width, uint8_t height) : Display(width, height) {
    // Initialize GPIO pins and layout
    for (const auto pin : kPins) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    delay(1000);
}

void FlipDotDisplay::drawPixel(uint8_t x, uint8_t y, bool toggle) {
    if (x >= kDisplayWidth || y >= kModuleHeight) {
        return;
    }

    byte module_idx = (x < kModuleWidth * kNumModules) ? x / kModuleWidth : kNumModules;
    byte offset = !!(module_idx - module_idx % kNumModules) * kColumnShortModule;
    byte column_module = x % kModuleWidth + offset;

    FlipDot(module_idx, y, column_module, toggle);
}

void FlipDotDisplay::clear() {
    for (uint8_t m = 0; m < arraysize(kModulePins); m++) {
        for (uint8_t c = GetModuleIndex(m); c < kModuleWidth; c++) {
            for (uint8_t r = 0; r < kModuleHeight; r++) {
                FlipDot(m, r, c, false);
            }
        }
    }
}

void TerminalDisplay::clearArea(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    for (uint8_t i = x; i < x + width; ++i) {
        for (uint8_t j = y; j < y + height; ++j) {
            drawPixel(x, y, false);
        }
    }
}

void FlipDotDisplay::fill() {
    for (uint8_t m = 0; m < arraysize(kModulePins); m++) {
        for (uint8_t c = GetModuleIndex(m); c < kModuleWidth; c++) {
            for (uint8_t r = 0; r < kModuleHeight; r++) {
                FlipDot(m, r, c, true);
            }
        }
    }
}

}  // namespace aivju