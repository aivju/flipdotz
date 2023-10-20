// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef UTILS_BASE_64_H_
#define UTILS_BASE_64_H_

#include <string>

namespace aivju {

std::string BinaryToByteString(const std::string& binary_str);
std::string ByteStringToBinary(const std::string& byte_string);

std::string Base64Encode(const std::string& input);
std::string Base64Decode(const std::string& input);

}  // namespace aivju

#endif  // UTILS_BASE_64_H_
