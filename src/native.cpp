// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <chrono>
#include <thread>

#include "clock_widget.h"
#include "date_widget.h"
#include "display.h"
#include "display_config.h"
#include "dotzfont_medium.h"
#include "dotzfont_small.h"
#include "renderer.h"
#include "weather_widget.h"
#include "text_scroller.h"

using namespace aivju;
TerminalDisplay* display;
Renderer* dashboard;

void setup() {
    display = new TerminalDisplay(kDisplayWidth, kDisplayHeight);
    dashboard = new Renderer(display);
    Font small(DotzFontSmall);
    Font medium(DotzFontMedium);
    dashboard->addWidget(ClockWidget(1, 1, medium));
    dashboard->addWidget(DateWidget(1, 10, small));
    dashboard->addWidget(WeatherWidget(48, 1, small, medium));
}

void loop() {
    dashboard->drawDisplay();
}

int main() {
    setup();
    while (true) {
        loop();
        std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    }
}