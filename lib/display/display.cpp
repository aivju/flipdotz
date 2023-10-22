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

Display::Display(uint8_t width, uint8_t height) : width_(width), height_(height) {}

uint8_t Display::getWidth() const {
    return width_;
}

uint8_t Display::getHeight() const {
    return height_;
}

}  // namespace aivju
