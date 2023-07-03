// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#ifndef LIB_DISPLAY_DISPLAY_CONFIG_H_
#define LIB_DISPLAY_DISPLAY_CONFIG_H_

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
const byte kModuleWidth = 28;
const byte kModuleHeight = 16;
const byte kNumModules = 4;
const byte kColumnOffsetShortModule = 14;
const byte kDisplayWidth = kModuleWidth * kNumModules + kColumnOffsetShortModule;
const byte kDisplayHeight = kModuleHeight;

} // namespace aivju

#endif // LIB_DISPLAY_DISPLAY_CONFIG_H_
