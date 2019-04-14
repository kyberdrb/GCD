#include <iostream>
#include "../../gcdFinder/GcdFinder.h"
#include <gtest/gtest.h>

namespace {
    class Test_GCD_7_5_12 : public ::testing::Test {
    protected:
        GcdFinder *gcdFinder = nullptr;
        const int numberOfNumbers = 3;
        int* numbers = nullptr;

        void SetUp() override
        {
            gcdFinder = new GcdFinder();
            numbers = (int*) calloc(numberOfNumbers, sizeof(int));
            numbers[0] = 7;
            numbers[1] = 5;
            numbers[2] = 12;
        }

        void TearDown() override
        {
            delete gcdFinder;
            free(numbers);
        }
    };

    TEST_F(Test_GCD_7_5_12, gcd_7_5_12) {
        ASSERT_EQ(1, gcdFinder->find_max_gcd(numbers, numberOfNumbers));
    }
}