#include <iostream>
#include "../../gcdFinder/GcdFinder.h"
#include <gtest/gtest.h>

namespace {
    class Test_GCD_10_20_30_40 : public ::testing::Test {
    protected:
        GcdFinder *gcdFinder = nullptr;
        const int numberOfNumbers = 4;
        int* numbers = nullptr;

        void SetUp() override
        {
            gcdFinder = new GcdFinder();
            numbers = (int*) calloc(numberOfNumbers, sizeof(int));
            numbers[0] = 10;
            numbers[1] = 20;
            numbers[2] = 30;
            numbers[3] = 40;
        }

        void TearDown() override
        {
            delete gcdFinder;
            free(numbers);
        }
    };

    TEST_F(Test_GCD_10_20_30_40, gcd_10_20_30_40) {
        ASSERT_EQ(20, gcdFinder->find_max_gcd(numbers, numberOfNumbers));
    }
}