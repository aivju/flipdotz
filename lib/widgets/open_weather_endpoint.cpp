// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "open_weather_endpoint.h"

#if defined(ARDUINO_LOLIN32)

#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

#include "credentials.h"
#include "weather_widget.h"

namespace aivju {
namespace {
std::pair<std::string, const uint16_t*> CoverageForIcon(const std::string& icon) {
    std::unordered_map<std::string, std::pair<std::string, const uint16_t*>> coverageMap = {
        {"01",   {"Heiter", k01Icon}},
        {"02",   {"Wolkig", k02Icon}},
        {"03",  {"Bedeckt", k03Icon}},
        {"04",   {"Wolken", k04Icon}},
        {"09",  {"Schauer", k09Icon}},
        {"10",    {"Regen", k10Icon}},
        {"11", {"Gewitter", k11Icon}},
        {"13",   {"Schnee", k13Icon}},
        {"50",    {"Nebel", k50Icon}}
    };

    std::string key = icon.substr(0, 2);
    if (coverageMap.find(key) != coverageMap.end()) {
        return coverageMap[key];
    } else {
        return {"Unknown", nullptr};  // Return nullptr if the icon is not found
    }
}

DeserializationError IsJsonTreeInvalid(const DynamicJsonDocument& doc) {
    if (!doc.containsKey("main") ||
        !doc.containsKey("weather")) {
        return DeserializationError::InvalidInput;
    }

    if (!doc["main"].containsKey("temp") ||
        !doc["main"].containsKey("temp_min") ||
        !doc["main"].containsKey("temp_max")) {
        return DeserializationError::InvalidInput;
    }

    return DeserializationError::Ok;
}

}  // namespace

const char* kOpenWeatherHost = "http://api.openweathermap.org";
const char* kCity = "Wiesbaden,DE";

bool FetchWeatherData(WeatherData &data) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        auto url = String(kOpenWeatherHost) + "/data/2.5/weather?q=" + kCity +
                   "&appid=" + kOpenWeatherAPIKey + "&units=metric";
        http.begin(url);

        if (http.GET() == HTTP_CODE_OK) {
            const auto payload = http.getString();
            DynamicJsonDocument doc(2048);
            auto error = deserializeJson(doc, payload);
            if (error || IsJsonTreeInvalid(doc)) {
                return false;
            }

            float tmp = doc["main"]["temp"];
            data.temperature = std::lrint(tmp);
            tmp = doc["main"]["temp_min"];
            data.temp_min = std::lrint(tmp);
            tmp = doc["main"]["temp_max"];
            data.temp_max = std::lrint(tmp);
            const char* icon = doc["weather"][0]["icon"];
            
            auto result = CoverageForIcon(icon);
            data.coverage = result.first;
            std::copy(result.second, result.second + 16, std::back_inserter(data.icon));
        }
    }

    return true;
}

}  // namespace aivju

#endif