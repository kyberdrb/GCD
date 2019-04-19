#include <iostream>
#include <gtest/gtest.h>
#include "../../../stringToNumberConverter/StringToNumberConverter.h"
#include "../../../convertedNumbers/ConvertedNumbers.h"

namespace {
    class Test_StringToNumberConverter : public ::testing::Test {
    protected:
        char *const args [4] = {"1", "-2", "asdf", "300.7"};
        int numberOfArguments = 4;

        std::unique_ptr<ConvertedNumbers> convertedNumbers = nullptr;

        void SetUp() override {
            convertedNumbers = StringToNumberConverter::createConvertedNumbers(args, numberOfArguments);
        }

        void TearDown() override {

        };
    };

    TEST_F( Test_StringToNumberConverter,
            convert_1) {
        int numberOfValidArguments = 3;
        EXPECT_EQ(numberOfValidArguments, convertedNumbers->getSize());
    }

    TEST_F( Test_StringToNumberConverter,
            compare_valid_numbers) {
        EXPECT_EQ(1, convertedNumbers->getConvertedNumbers()[0]);
        EXPECT_EQ(-2, convertedNumbers->getConvertedNumbers()[1]);
        EXPECT_EQ(300, convertedNumbers->getConvertedNumbers()[2]);
    }
}