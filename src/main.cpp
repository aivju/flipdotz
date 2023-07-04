// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted

#include <Arduino.h>
#include "display.h"
#include "display_config.h"

using namespace aivju;
const int kPauseBetweenActionsInMs = 3000;

FlipDotDisplay *display;
void setup() {
  display = new FlipDotDisplay(kDisplayWidth, kDisplayHeight);
}

void loop() {
  display->clear();
  delay(kPauseBetweenActionsInMs);
  for (uint8_t y = 0; y < kDisplayHeight; y++) {
    for (uint8_t x = 0; x < kDisplayWidth; x++) {
      display->setPixel(x, y, true);
    }
  }
}
