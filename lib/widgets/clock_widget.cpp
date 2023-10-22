// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "clock_widget.h"

#include "datetime.h"

namespace aivju {

ClockWidget::ClockWidget(uint8_t x, uint8_t y, const Font& font) : clock_("", x, y, font) {}

void ClockWidget::render(Display* display) {
    clock_.setText(CurrentTime());
    clock_.render(display);
}

}  // namespace aivju