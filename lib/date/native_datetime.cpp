// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <ctime>
#include <iomanip>
#include <memory>

#include "datetime.h"
#include "macros.h"

namespace aivju {

std::unique_ptr<tm> TimeInfo() {
    std::locale::global(std::locale("de_DE.UTF-8"));
    time_t raw_time;
    std::time(&raw_time);
    tm* local_tm = localtime(&raw_time);
    return make_unique<tm>(*local_tm);
}

}  // namespace aivju