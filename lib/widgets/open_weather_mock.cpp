// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <algorithm>
#include <iterator>
#include <random>
#include <string>
#include <vector>

#include "open_weather_endpoint.h"
#include "weather_widget.h"

namespace aivju {
namespace {
template <typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template <typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}
}  // namespace

WeatherData FetchWeatherData() {
    WeatherData data;

    int range = 38 - 10 + 1;
    int num = rand() % range + 10;
    std::vector<std::string> coverages{"sonnig", "heiter", "sonnig", "heiter", "sonnig"};

    std::copy(k01Icon, k01Icon + 16, std::back_inserter(data.icon));
    data.temperature = num;
    data.coverage = *select_randomly(coverages.begin(), coverages.end());
    data.temp_min = num - 3;
    data.temp_max = num + 6;

    return data;
}

}  // namespace aivju