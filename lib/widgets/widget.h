// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef WIDGETS_WIDGET_H_
#define WIDGETS_WIDGET_H_

#include "display.h"

namespace aivju {

class Widget {
  public:
    virtual ~Widget() = default;
    virtual void render(Display* display) = 0;
};
}  // namespace aivju

#endif  // WIDGETS_WIDGET_H_
