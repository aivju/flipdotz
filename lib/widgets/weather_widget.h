// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef WIDGETS_WEATHER_WIDGETS_H_
#define WIDGETS_WEATHER_WIDGETS_H_

#include "font.h"
#include "icon_element.h"
#include "open_weather_endpoint.h"
#include "text_element.h"
#include "widget.h"

#include <cstdint>
#include <ctime>

namespace aivju {

// The following symbol descriptions map to the official OpenWeather API
// See: https://openweathermap.org/weather-conditions for more info

// clear sky
const uint16_t k01Icon[] = {0x0,   0x100, 0x100, 0x1110, 0x820, 0x380, 0x7c0, 0x77dc,
                            0x7c0, 0x380, 0x820, 0x1110, 0x100, 0x100, 0x0,   0x0};

// few clouds
const uint16_t k02Icon[] = {0x0,    0x2400, 0x15f0, 0x110, 0x6f10, 0xf10, 0x3f1e, 0x2f02,
                            0x2002, 0x3ffe, 0x0,    0x0,   0x0,    0x0,   0x0,    0x0};

// scattered clouds
const uint16_t k03Icon[] = {0x0,    0x0,    0x1f0, 0x110, 0xf10, 0x810, 0x381e, 0x2002,
                            0x2002, 0x3ffe, 0x0,   0x0,   0x0,   0x0,   0x0,    0x0};

// broken clouds
const uint16_t k04Icon[] = {0x0,    0x0,    0x3c0,  0x240,  0x1e70, 0x1050, 0x7078, 0x4008,
                            0x400e, 0x7ffa, 0x1002, 0x1ffe, 0x0,    0x0,    0x0,    0x0};

// shower rain
const uint16_t k09Icon[] = {0x0,    0x0,    0x1f0, 0x110, 0xf10, 0x810, 0x381e, 0x2002,
                            0x240a, 0x3ffe, 0x528, 0x20,  0x508, 0x120, 0x0,    0x0};

// rain
const uint16_t k10Icon[] = {0x0,    0x2400, 0x15f0, 0x110, 0x6f10, 0xf10, 0x3f1e, 0x2f02,
                            0x200a, 0x3ffe, 0x528,  0x20,  0x508,  0x120, 0x0,    0x0};

// thunderstorm
const uint16_t k11Icon[] = {0x0,    0x0,    0x1f0, 0x110, 0xf10, 0x810, 0x39de, 0x21c2,
                            0x29ca, 0x3ffe, 0xb88, 0x320, 0x620, 0x400, 0x0,    0x0};

// snow
const uint16_t k13Icon[] = {0x0,    0x0,   0x380,  0x920, 0x1930, 0x540, 0x2288, 0x3c78,
                            0x2288, 0x540, 0x1930, 0x920, 0x380,  0x0,   0x0,    0x0};

// mist
const uint16_t k50Icon[] = {0x0,    0x0, 0x380, 0x0, 0x3fc0, 0x0, 0x7fc, 0x0,
                            0x7fc0, 0x0, 0xfe0, 0x0, 0x7f0,  0x0, 0x0,   0x0};

class WeatherWidget : public Widget {
  public:
    WeatherWidget(uint8_t x, uint8_t y, const Font& small, const Font& medium);
    void render(Display* display) override;

  private:
    void updateWeatherData();

    uint8_t x_, y_;
    std::time_t last_api_call_;
    IconElement weather_icon_;
    TextElement temperature_;
    TextElement coverage_;
    TextElement max_temp_, min_temp_;
    WeatherData data_;
};

}  // namespace aivju

#endif  // WIDGETS_WEATHER_WIDGETS_H_
