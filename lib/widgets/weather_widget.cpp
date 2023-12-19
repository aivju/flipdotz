// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "weather_widget.h"

#include "open_weather_endpoint.h"
#include "str_format.h"

namespace aivju {
const uint8_t kTempOffset = 19;
const uint8_t kMinMaxOffset = 59;

WeatherWidget::WeatherWidget(uint8_t x, uint8_t y, const Font& small, const Font& medium)
    : x_(x),
      y_(y),
      weather_icon_(k01Icon, x, y-1),
      temperature_("", x + kTempOffset, y, medium),
      coverage_("", x + kTempOffset, y + 9, small),
      max_temp_("", x + kMinMaxOffset, y, small),
      min_temp_("", x + kMinMaxOffset, y + 9, small) {
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
        max_temp_.render(display);
        min_temp_.render(display);

        last_api_call_ = current_time;
    }
}

void WeatherWidget::updateWeatherData() {
    if (!FetchWeatherData(data_)) {
        return;
    }

    temperature_.setText(StrFormat("%02d* C", data_.temperature));
    weather_icon_.setData(data_.icon);
    coverage_.setText(data_.coverage);
    min_temp_.setText(StrFormat("< %02d* C", data_.temp_min));
    max_temp_.setText(StrFormat("> %02d* C", data_.temp_max));
}

}  // namespace aivju
