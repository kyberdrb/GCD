#include <iostream>
#include "../../gcdFinder/GcdFinder.h"
#include <gtest/gtest.h>

namespace {
    class Test_GCD_3 : public ::testing::Test {
    protected:
        GcdFinder *gcdFinder = nullptr;
        const int numberOfNumbers = 1;
        int* numbers = nullptr;

        void SetUp() override
        {
            gcdFinder = new GcdFinder();
            numbers = (int*) calloc(numberOfNumbers, sizeof(int));
            numbers[0] = 3;
        }

        void TearDown() override
        {
            delete gcdFinder;
            free(numbers);
        }
    };

    TEST_F(Test_GCD_3, gcd_3) {
        ASSERT_EQ(3, gcdFinder->find_max_gcd(numbers, numberOfNumbers));
    }
}