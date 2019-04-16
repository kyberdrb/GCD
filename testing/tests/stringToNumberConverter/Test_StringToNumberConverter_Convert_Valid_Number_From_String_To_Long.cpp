#include <iostream>
#include <gtest/gtest.h>
#include "../../../stringToNumberConverter/StringToNumberConverter.h"

namespace {
    class Test_StringToNumberConverter_Convert_Valid_Number_From_String_To_Long : public ::testing::Test {};

    TEST_F(
            Test_StringToNumberConverter_Convert_Valid_Number_From_String_To_Long,
            convert_1_From_String_To_Long) {
        ASSERT_EQ(1, StringToNumberConverter::convert("1"));
    }

    TEST_F(
            Test_StringToNumberConverter_Convert_Valid_Number_From_String_To_Long,
            convert_100_From_String_To_Long) {
        ASSERT_EQ(100, StringToNumberConverter::convert("100"));
    }

    // TODO make more test cases:
    //  - negative numbers
    //  - string literals
}