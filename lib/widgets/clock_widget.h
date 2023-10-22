// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef WIDGETS_CLOCK_WIDGET_H_
#define WIDGETS_CLOCK_WIDGET_H_

#include <cstdint>

#include "display.h"
#include "font.h"
#include "text_element.h"
#include "widget.h"

namespace aivju {

class ClockWidget : public Widget {
  public:
    ClockWidget(uint8_t x, uint8_t y, const Font& font);
    void render(Display* display) override;

  private:
    TextElement clock_;
};

}  // namespace aivju

#endif  // WIDGETS_CLOCK_WIDGET_H_
