// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "open_weather_endpoint.h"

#if defined(ARDUINO_LOLIN32)

#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include <cmath>
#include "credentials.h"

namespace aivju {

const char* kOpenWeatherHost = "http://api.openweathermap.org";
const char* kCity = "Wiesbaden,DE";

WeatherData FetchWeatherData() {
    WeatherData data;
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        auto url = String(kOpenWeatherHost) + "/data/2.5/weather?q=" + kCity +
                   "&appid=" + kOpenWeatherAPIKey + "&units=metric";
        http.begin(url);

        auto http_response = http.GET();
        if (http_response > 0) {
            const auto payload = http.getString();
            DynamicJsonDocument doc(2048);
            deserializeJson(doc, payload);

            float tmp = doc["main"]["temp"];
            data.temperature = std::lrint(tmp);
            tmp = doc["main"]["temp_min"];
            data.temp_min = std::lrint(tmp);
            tmp = doc["main"]["temp_max"];
            data.temp_max = std::lrint(tmp);
            const char* icon = doc["weather"][0]["icon"];
            data.icon = icon;
        }
    }

    return data;
}

}  // namespace aivju

#endif