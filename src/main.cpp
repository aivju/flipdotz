// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted

#include <Arduino.h>
#include <WiFi.h>

#include <ctime>
#include <deque>

#include "clock_widget.h"
#include "credentials.h"
#include "date_widget.h"
#include "display.h"
#include "display_config.h"
#include "dotzfont_medium.h"
#include "dotzfont_small.h"
#include "renderer.h"
#include "weather_widget.h"

using namespace aivju;
FlipDotDisplay* display;
Renderer* dashboard;

const char* kNTPServer = "europe.pool.ntp.org";

void connectWifi() {
    Serial.begin(MONITOR_SPEED);
    Serial.printf("Connecting to: %s\n", kSSID);

    WiFi.begin(kSSID, kPassword);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
}

void configureTime() {
    configTime(3600, 3600, kNTPServer);
    Serial.println("Waiting for time");
    while (!time(nullptr)) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("");
}

void setup() {
    display = new FlipDotDisplay(kDisplayWidth, kDisplayHeight);
    display->clear();

    connectWifi();
    configureTime();

    display = new FlipDotDisplay(kDisplayWidth, kDisplayHeight);
    dashboard = new Renderer(display);

    Font small(DotzFontSmall);
    Font medium(DotzFontMedium);
    dashboard->addWidget(ClockWidget(1, 1, medium));
    dashboard->addWidget(DateWidget(1, 10, small));
    dashboard->addWidget(WeatherWidget(50, 1, small, medium));
}

void loop() {
    dashboard->drawDisplay();
}
