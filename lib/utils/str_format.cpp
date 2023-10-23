// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef UTILS_STR_FORMAT_H_
#define UTILS_STR_FORMAT_H_

#include <cstdarg>
#include <string>
#include <vector>

namespace aivju {

std::string StrFormat(const char* const format, ...) {
    va_list va_args;
    va_start(va_args, format);

    va_list va_args_copy;
    va_copy(va_args_copy, va_args);
    const int len = std::vsnprintf(nullptr, 0, format, va_args_copy);
    va_end(va_args_copy);

    std::vector<char> zc(len + 1);
    std::vsnprintf(zc.data(), zc.size(), format, va_args);
    va_end(va_args);
    return std::string(zc.data(), len);
}

}  // namespace aivju

#endif  // UTILS_STR_FORMAT_H_
