// Copyright (c) 2024 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef WIDGETS_SPACESHIP_WIDGET_H_
#define WIDGETS_SPACESHIP_WIDGET_H_

#include "widget.h"

#include <cstdint>

namespace aivju {

class SpaceshipWidget : public Widget {
  public:
    SpaceshipWidget(uint8_t x, uint8_t y, unsigned long rnd = 0);
    void render(Display* display) override;

  private:
    uint8_t x_, y_;
    unsigned long seed_;
};

}  // namespace aivju

#endif  // WIDGETS_SPACESHIP_WIDGET_H_
