// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef RENDERER_H_
#define RENDERER_H_

#include <memory>
#include <vector>

#include "clock_widget.h"
#include "display.h"
#include "element.h"
#include "font.h"
#include "widget.h"
#include "macros.h"
#include "clock_widget.h"

namespace aivju {

class Renderer {
  public:
    explicit Renderer(Display* display);
    void drawDisplay();

    template <typename T>
    void addWidget(const T& widget) {
        using namespace std;
        elements_.push_back(make_unique<T>(widget));
    }

  private:
    Display* display_;
    std::vector<std::unique_ptr<Widget>> elements_;
};

}  // namespace aivju

#endif  // RENDERER_H_
