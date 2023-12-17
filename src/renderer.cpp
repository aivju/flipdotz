// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "renderer.h"

namespace aivju {

Renderer::Renderer(Display* display) : display_(display) {}

void Renderer::drawDisplay() {
    for (const auto& ele : elements_) {
        ele->render(display_);
    }
    display_->render();
}

}  // namespace aivju