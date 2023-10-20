// Copyright (c) 2023 aivju GmbH
// All rights reserved. Redistribution and use in source and binary forms,
// with or without modification, are not permitted.

#include <unity.h>

#include "display.h"
#include "display_config.h"

using namespace aivju;

void setUp() {}
void tearDown() {}

void test_display_large_modules_calculation() {
    // first module
    for (uint8_t x = 0; x < kModuleWidth; x++) {
        TEST_ASSERT_EQUAL(GetModuleIndex(x), 0);
    }

    // second module
    for (uint8_t x = kModuleWidth; x < 2 * kModuleWidth; x++) {
        TEST_ASSERT_EQUAL(GetModuleIndex(x), 1);
    }

    // third module
    for (uint8_t x = 2 * kModuleWidth; x < 3 * kModuleWidth; x++) {
        TEST_ASSERT_EQUAL(GetModuleIndex(x), 2);
    }

    // fourth module
    for (uint8_t x = 3 * kModuleWidth; x < 4 * kModuleWidth; x++) {
        TEST_ASSERT_EQUAL(GetModuleIndex(x), 3);
    }
}

void test_display_offset_small_module_calculation() {
    TEST_ASSERT_LESS_THAN_UINT8(kDisplayWidth, 4 * kModuleWidth);
    for (uint8_t x = 4 * kModuleWidth; x < kDisplayWidth; x++) {
        TEST_ASSERT_EQUAL(GetModuleIndex(x), 4);
    }
}

void RUN_UNITY_TESTS() {
    UNITY_BEGIN();
    RUN_TEST(test_display_large_modules_calculation);
    RUN_TEST(test_display_offset_small_module_calculation);
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