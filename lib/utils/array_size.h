// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef ARRAY_SIZE_H_
#define ARRAY_SIZE_H_

#include <cstddef>

namespace aivju {
namespace internal {

// The arraysize(arr) macro returns the number of elements in array.
// The expression is a compile-time constant, and therefore can be used in
// defining new arrays, for example. If you use arraysize on a pointer by
// mistake, you will get a compile-time error, since *foo_ and foo_[] are
// two different things.
template <typename T, std::size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];

#define arraysize(arr) (sizeof(::aivju::internal::ArraySizeHelper(arr)))
}  // namespace internal

// Used to explicitly mark the return value of a function as unused.
template <typename T>
inline void IgnoreResult(const T& /*unused*/) {}
}  // namespace aivju

#endif  // ARRAY_SIZE_H_
