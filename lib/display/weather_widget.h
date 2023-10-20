// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef DISPLAY_SYMBOLS_H_
#define DISPLAY_SYMBOLS_H_

#include <string>

namespace aivju {

// The following symbol descriptions map to the official OpenWeather API
// in Base64 encoding.
// See: https://openweathermap.org/weather-conditions for more info

// clear sky
const std::string k01 = "AAABAAEAERAIIAOAB8B33AfAA4AIIBEQAQABAAAAAAA=";

// few clouds
const std::string k02 = "AAAkABXwARBvEA8QPx4vAiACP/4AAAAAAAAAAAAAAAA=";

// scattered clouds
const std::string k03 = "AAAAAAHwARAPEAgQOB4gAiACP/4AAAAAAAAAAAAAAAA=";

// broken clouds
const std::string k04 = "AAAAAAPAAkAecBBQcHhACEAOf/oQAh/+AAAAAAAAAAA=";

// shower rain
const std::string k09 = "AAADwAJAHnAQUHB4QAhEDn/6FEIf/gFQBBAEQABAAAA=";

// rain
const std::string k10 = "AAAkABXwARBvEA8QPx4vAiAKP/4FKAAgBQgBIAAAAAA=";

// thunderstorm
const std::string k11 = "AAAAAAHwARAPEAgQOd4hwinKP/4LiAMgBiAEAAAAAAA=";

// snow
const std::string k13 = "AAAAAAOACSAZMAVAIog8eCKIBUAZMAkgA4AAAAAAAAA=";

// mist
const std::string k50 = "AAAAAAOAAAA/wAAAB/wAAH/AAAAP4AAAB/AAAAAAAAA=";

// beer
const std::string kBeer = "AAADgA6ACPA4ECAQP/AQIBQ4EKQQJBEkFDgQIB/gAAA=";
}  // namespace aivju

#endif  // DISPLAY_SYMBOLS_H_
