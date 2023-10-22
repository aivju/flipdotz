// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "date_widget.h"

#include "datetime.h"

namespace aivju {

DateWidget::DateWidget(uint8_t x, uint8_t y, const Font& font) : date_("", x, y, font) {}

void DateWidget::render(Display* display) {
    date_.setText(CurrentDate());
    date_.render(display);
}

}  // namespace aivju