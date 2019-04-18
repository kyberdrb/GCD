#include <iostream>
#include <gtest/gtest.h>
#include "../../../stringToNumberConverter/StringToNumberConverter.h"

namespace {
    class Test_StringToNumberConverter : public ::testing::Test {
    protected:
        char *const args [4] = {"1", "-2", "asdf", "300.7"};
        int numberOfArguments = 4;

        int *convertedNumbers = nullptr;

        void SetUp() override {
            convertedNumbers = StringToNumberConverter::createConvertedNumbers(args, numberOfArguments);
        }

        void TearDown() override {
            free(convertedNumbers);
        };
    };

    TEST_F( Test_StringToNumberConverter,
            convert_1) {
        int numberOfValidArguments = 3;
        EXPECT_EQ(numberOfValidArguments, numberOfArguments);
    }

    TEST_F( Test_StringToNumberConverter,
            compare_valid_numbers) {
        EXPECT_EQ(1, convertedNumbers[0]);
        EXPECT_EQ(-2, convertedNumbers[1]);
        EXPECT_EQ(300, convertedNumbers[2]);
    }
}