// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "weather_widget.h"

#include "open_weather_endpoint.h"
#include "str_format.h"

namespace aivju {

WeatherWidget::WeatherWidget(uint8_t x, uint8_t y, const Font& small, const Font& medium)
    : x_(x),
      y_(y),
      temperature_("", x + 20, y, medium),
      coverage_("", x + 20, y + 10, small),
      min_temp_("", x + 60, y, small),
      max_temp_("", x + 60, y + 10, small),
      weather_icon_(k09Icon, x, y) {
    last_api_call_ = 0;
}

void WeatherWidget::render(Display* display) {
    auto current_time = std::time(nullptr);

    if (current_time - last_api_call_ >= 1) {
        updateWeatherData();

        weather_icon_.render(display);
        temperature_.render(display);
        // TODO(kai): Fix overdrawing bug
        //display->clearArea(x_ + 20, y_ + 10, 35, 5);
        coverage_.render(display);
        min_temp_.render(display);
        max_temp_.render(display);

        last_api_call_ = current_time;
    }
}

void WeatherWidget::updateWeatherData() {
    auto data = FetchWeatherData();

    temperature_.setText(StrFormat("%02d* C", data.temperature));
    weather_icon_.setData(data.icon);
    coverage_.setText(data.coverage);
    min_temp_.setText(StrFormat("%02d* C", data.temp_min));
    max_temp_.setText(StrFormat("%02d* C", data.temp_max));
}

}  // namespace aivju
