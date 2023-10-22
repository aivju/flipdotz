// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef DISPLAY_DISPLAY_H_
#define DISPLAY_DISPLAY_H_

#include <cstdint>

namespace aivju {
uint8_t GetModuleIndex(uint8_t x);

// Interface for display provider mainly used for testing purposes
class Display {
  public:
    Display(uint8_t width, uint8_t height);
    uint8_t getWidth() const;
    uint8_t getHeight() const;
    virtual void setPixel(uint8_t x, uint8_t y, bool toggle);
    virtual void drawPixel(uint8_t x, uint8_t y, bool toggle) = 0;
    virtual void clear() = 0;
    virtual void fill() = 0;
    void render();

  protected:
    uint8_t width_;
    uint8_t height_;
    bool** current_buffer;
    bool** next_buffer;
};

class FlipDotDisplay : public Display {
  public:
    FlipDotDisplay(uint8_t width, uint8_t height);
    void drawPixel(uint8_t x, uint8_t y, bool toggle) override;
    void clear() override;
    void fill() override;
};

class TerminalDisplay : public Display {
  public:
    TerminalDisplay(uint8_t width, uint8_t height);
    void drawPixel(uint8_t x, uint8_t y, bool toggle) override;
    void show();
    void clear() override;
    void fill() override;
};

}  // namespace aivju

#endif  // DISPLAY_DISPLAY_H_
