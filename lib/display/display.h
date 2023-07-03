// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef DISPLAY_DISPLAY_H_
#define DISPLAY_DISPLAY_H_

#include <Arduino.h>

namespace aivju {

// Interface for display provider mainly used for testing purposes
class Display {
public:
  Display(byte width, byte height);
  virtual void setPixel(byte x, byte y, bool toggle) = 0;
  virtual void clear() = 0;
  virtual void fill() = 0;

protected:
  byte width_;
  byte height_;
};

class FlipDotDisplay : public Display {
public:
  FlipDotDisplay(byte width, byte height);
  void setPixel(byte x, byte y, bool toggle) override;
  void clear() override;
  void fill() override;
};

class TerminalDisplay : public Display {
public:
  TerminalDisplay(byte width, byte height);
  void setPixel(byte x, byte y, bool toggle) override;
  void clear() override;
  void fill() override;
};

} // namespace aivju

#endif // DISPLAY_DISPLAY_H_
