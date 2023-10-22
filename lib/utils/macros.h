// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef UTILS_MACROS_H_
#define UTILS_MACROS_H_

#include <memory>

#if __cplusplus >= 201402L
usig std::make_unique;
#else
template <typename T, typename... Args>
typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T> >::type make_unique(
    Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

/// Allows 'make_unique<T[]>(10)'. (N3690 s20.9.1.4 p3-4)
template <typename T>
typename std::enable_if<std::is_array<T>::value, std::unique_ptr<T> >::type make_unique(
    const size_t n) {
    return std::unique_ptr<T>(new typename std::remove_extent<T>::type[n]());
}

/// Disallows 'make_unique<T[10]>()'. (N3690 s20.9.1.4 p5)
template <typename T, typename... Args>
typename std::enable_if<std::extent<T>::value != 0, std::unique_ptr<T> >::type make_unique(
    Args&&...) = delete;
#endif

#endif  // UTILS_MACROS_H_
