// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "datetime.h"

#include "str_format.h"

namespace aivju {
namespace {
tm TimeInfo() {
    time_t now;
    struct tm timeinfo {};

    time(&now);
    setenv("TZ", "Europe/Berlin", 1);
    tzset();

    localtime_r(&now, &timeinfo);
    return timeinfo;
}

}  // namespace

std::string CurrentTime() {
    auto timeinfo = TimeInfo();
    return StrFormat("%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min);
}

std::string CurrentDate() {
    char buf[64];
    auto timeinfo = TimeInfo();
    strftime(buf, sizeof(buf), "%a %e.%b", &timeinfo);
    return {buf};
}

}  // namespace aivju