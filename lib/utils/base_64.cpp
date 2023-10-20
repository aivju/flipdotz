// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "base_64.h"

namespace aivju {
namespace {
const std::string kBase64Chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
}  // namespace

std::string BinaryToByteString(const std::string& binary_str) {
    std::string byte_string;
    for (int i = 0; i < binary_str.size(); i += 8) {
        char byte = static_cast<char>(std::stoi(binary_str.substr(i, 8), nullptr, 2));
        byte_string.push_back(byte);
    }
    return byte_string;
}

std::string ByteStringToBinary(const std::string& byte_string) {
    std::string binary_str;
    for (char byte : byte_string) {
        for (int i = 7; i >= 0; --i) {
            binary_str.push_back((byte & (1 << i)) ? '1' : '0');
        }
    }
    return binary_str;
}

std::string Base64Encode(const std::string& input) {
    std::string byte_string = BinaryToByteString(input);
    std::string encoded;
    int val = 0;
    int valb = -6;

    for (char c : byte_string) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            encoded.push_back(kBase64Chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    if (valb > -6)
        encoded.push_back(kBase64Chars[((val << 8) >> (valb + 8)) & 0x3F]);
    while (encoded.size() % 4)
        encoded.push_back('=');

    return encoded;
}

std::string Base64Decode(const std::string& input) {
    static const int decoding_table[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62,
        -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1, -1, 0,
        1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
        23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1};

    std::string byte_string;
    int val = 0, valb = -8;

    for (char c : input) {
        if (c == '=')
            break;  // Padding character
        if (decoding_table[c] == -1)
            continue;  // Character not in Base64 set
        val = (val << 6) + decoding_table[c];
        valb += 6;
        if (valb >= 0) {
            byte_string.push_back(static_cast<char>((val >> valb) & 0xFF));
            valb -= 8;
        }
    }

    return byte_string;
}

}  // namespace aivju
