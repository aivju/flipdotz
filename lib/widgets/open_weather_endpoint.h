// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef OPEN_WEATHER_ENDPOINT_H_
#define OPEN_WEATHER_ENDPOINT_H_

#include <cstdint>
#include <string>
#include <vector>

namespace aivju {

struct WeatherData {
    int temperature;
    int temp_min;
    int temp_max;
    std::vector<uint16_t> icon;
    std::string coverage;
};

bool FetchWeatherData(WeatherData &data);

}  // namespace aivju

#endif  // OPEN_WEATHER_ENDPOINT_H_
