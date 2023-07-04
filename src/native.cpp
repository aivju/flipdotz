// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <iostream>
#include "display.h"
#include "display_config.h"

using namespace aivju;

int main() {
  TerminalDisplay display(kDisplayWidth, kDisplayHeight);
  display.setPixel(1, 1, true);
  display.setPixel(2, 2, true);
  return 0;
}