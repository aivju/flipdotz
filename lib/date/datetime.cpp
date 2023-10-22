// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "datetime.h"
#include "str_format.h"

namespace aivju {

std::string CurrentTime() {
    auto timeinfo = TimeInfo();
    return StrFormat("%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min);
}

std::string CurrentDate() {
    char buf[64];
    auto timeinfo = TimeInfo();
    strftime(buf, sizeof(buf), "%a %e.%b", timeinfo.get());
    return {buf};
}

}  // namespace aivju