// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef CONFIG_H_
#define CONFIG_H_

#include <cstdint>

namespace aivju {

// Adjusted pin assignments from LAWO ESP32 controller PCB by nalx @ section77
static uint8_t kPins[]{
    1,  //  [0] DATA
    21, //  [1] COLUMN_1
    19, //  [2] COLUMN_2
    23, //  [3] COLUMN_3
    18, //  [4] COLUMN_4
    5,  //  [5] COLUMN_5
    17, //  [6] ROW_1
    16, //  [7] ROW_2
    4,  //  [8] ROW_3
    22, //  [9] ROW_4
    2,  // [10] ENABLE_SET
    15, // [11] ENABLE_RESET
    13, // [12] MODULE_1
    12, // [13] MODULE_2
    14, // [14] MODULE_3
    27, // [15] MODULE_4
    26  // [16] MODULE_5
};

// clang-format off
const uint8_t kModulePins[] = {kPins[12], kPins[13], kPins[14], kPins[15], kPins[16]};
const uint8_t kColumnBitPins[] = {kPins[1], kPins[2], kPins[3], kPins[4], kPins[5]};
const uint8_t kRowBitPins[] = {kPins[6], kPins[7], kPins[8], kPins[9]};
// clang-format on
const int kDelayHighPulsInUs = 750;
const int kDelayFlipPulsInUs = 100;
const int kPauseBetweenDotFlipsInMs = 2;

} // namespace aivju

#endif // CONFIG_H_
