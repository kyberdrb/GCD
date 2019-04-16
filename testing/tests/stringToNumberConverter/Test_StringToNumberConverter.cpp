#include <iostream>
#include <gtest/gtest.h>
#include "../../../stringToNumberConverter/StringToNumberConverter.h"

namespace {
    class Test_StringToNumberConverter : public ::testing::Test {};

    TEST_F( Test_StringToNumberConverter,
            convert_1) {
        ASSERT_EQ(1, StringToNumberConverter::convert("1"));
    }

    TEST_F( Test_StringToNumberConverter,
            convert_100) {
        ASSERT_EQ(100, StringToNumberConverter::convert("100"));
    }

    TEST_F( Test_StringToNumberConverter,
            convert_negative_30) {
        ASSERT_EQ(-30, StringToNumberConverter::convert("-30"));
    }

    TEST_F( Test_StringToNumberConverter,
            convert_garbled_ascii_string) {
        EXPECT_THROW(StringToNumberConverter::convert("asdf"), std::invalid_argument);
    }
}