// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef DISPLAY_DISPLAY_CONFIG_H_
#define DISPLAY_DISPLAY_CONFIG_H_

#include <cstdint>

namespace aivju {

// Display configuration for Dotze Dudes Office (126 x 16)
//
//      0            1            2            3            4
//     +----------+ +----------+ +----------+ +----------+ +------+
//     |    28    | |    28    | |    28    | |    28    | |  14  |
//     |16        | |16        | |16        | |16        | |16    |
//     |          | |          | |          | |          | |      |
//     +----------+ +----------+ +----------+ +----------+ +------+
//
const uint8_t kModuleHeight = 16;
const uint8_t kModuleWidth = 28;
const uint8_t kColumnShortModule = 14;
const uint8_t kNumModules = 4;
const uint8_t kDisplayWidth = kModuleWidth * kNumModules + kColumnShortModule;
const uint8_t kDisplayHeight = kModuleHeight;

}  // namespace aivju

#endif  // DISPLAY_DISPLAY_CONFIG_H_
