#include <iostream>
#include "../../gcdFinder/GcdFinder.h"
#include <gtest/gtest.h>

namespace {
    class Test_GCD : public ::testing::Test {};

    TEST_F(Test_GCD, gcd_10_20_30_40) {
        int numbers [] = {10, 20, 30, 40};
        EXPECT_EQ(20, GcdFinder::find_max_gcd(numbers, 4));
    }

    TEST_F(Test_GCD, gcd_7_5_12) {
        int numbers [] = {7, 5, 12};
        EXPECT_EQ(1, GcdFinder::find_max_gcd(numbers, 3));
    }

    TEST_F(Test_GCD, gcd_125_15_25) {
        int numbers [] = {125, 15, 25};
        EXPECT_EQ(25, GcdFinder::find_max_gcd(numbers, 3));
    }

    TEST_F(Test_GCD, gcd_3) {
        int numbers [] = {3};
        EXPECT_EQ(3, GcdFinder::find_max_gcd(numbers, 1));
    }

// TODO add more test-case-classes
//  0
//  0, 0
//  -1, -1
//  -2, -4
//  -20, -5
//  -150, -50, -160
//  -30, 6
//  45, -9
//  11, a
//  a, b
}
