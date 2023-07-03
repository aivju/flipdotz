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
  display = new FlipDotDisplay(kDisplayWidth, kDisplayWidth);
}

void loop() {
  display->clear();
  delay(kPauseBetweenActionsInMs);
  display->fill();
  delay(kPauseBetweenActionsInMs);
}
