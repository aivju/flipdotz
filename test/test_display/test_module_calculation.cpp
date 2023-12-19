// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include "display.h"
#include "display_config.h"

#include <unity.h>

using namespace aivju;

void setUp() {}
void tearDown() {}

void test_display_large_modules_calculation() {
    for (uint8_t idx = 0; idx < kNumModules; idx++) {
        TEST_ASSERT_EQUAL(GetModuleIndex(idx), 0);
    }
    TEST_ASSERT_EQUAL(GetModuleIndex(kNumModules), 14);
}

void test_display_indexing() {
    TEST_ASSERT_LESS_THAN_UINT8(kDisplayWidth, 4 * kModuleWidth);
}

void RUN_UNITY_TESTS() {
    UNITY_BEGIN();
    RUN_TEST(test_display_large_modules_calculation);
    RUN_TEST(test_display_indexing);
    UNITY_END();
}

#ifdef ARDUINO
    #include <Arduino.h>

void setup() {
    delay(2000);
    RUN_UNITY_TESTS();
}

void loop() {}

#else
int main(int argc, char* argv[]) {
    RUN_UNITY_TESTS();
    return 0;
}

#endif