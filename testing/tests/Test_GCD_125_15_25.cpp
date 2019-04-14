#include <iostream>
#include "../../gcdFinder/GcdFinder.h"
#include <gtest/gtest.h>

namespace {
    class Test_GCD_125_15_25 : public ::testing::Test {
    protected:
        GcdFinder *gcdFinder = nullptr;
        const int numberOfNumbers = 3;
        int* numbers = nullptr;

        void SetUp() override
        {
            gcdFinder = new GcdFinder();
            numbers = (int*) calloc(numberOfNumbers, sizeof(int));
            numbers[0] = 125;
            numbers[1] = 15;
            numbers[2] = 25;
        }

        void TearDown() override
        {
            delete gcdFinder;
            free(numbers);
        }
    };

    TEST_F(Test_GCD_125_15_25, gcd_125_15_25) {
        ASSERT_EQ(25, gcdFinder->find_max_gcd(numbers, numberOfNumbers));
    }
}