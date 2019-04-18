#include <iostream>
#include "../../../gcdFinder/GcdFinder.h"
#include <gtest/gtest.h>

namespace {
    class Test_GcdFinder : public ::testing::Test {};

    TEST_F(Test_GcdFinder, gcd_10_20_30_40) {
        int numbers [] = {10, 20, 30, 40};
        EXPECT_EQ(20, GcdFinder::find_max_gcd(numbers, 4));
    }

    TEST_F(Test_GcdFinder, gcd_7_5_12) {
        int numbers [] = {7, 5, 12};
        EXPECT_EQ(1, GcdFinder::find_max_gcd(numbers, 3));
    }

    TEST_F(Test_GcdFinder, gcd_125_15_25) {
        int numbers [] = {125, 15, 25};
        EXPECT_EQ(25, GcdFinder::find_max_gcd(numbers, 3));
    }

    TEST_F(Test_GcdFinder, gcd_3) {
        int numbers [] = {3};
        EXPECT_EQ(3, GcdFinder::find_max_gcd(numbers, 1));
    }

    TEST_F(Test_GcdFinder, gcd_0) {
        int numbers [] = {0};
        EXPECT_EQ(0, GcdFinder::find_max_gcd(numbers, 1));
    }

    TEST_F(Test_GcdFinder, gcd_0_0) {
        int numbers [] = {0, 0};
        EXPECT_EQ(0, GcdFinder::find_max_gcd(numbers, 2));
    }

    TEST_F(Test_GcdFinder, gcd_neg_1_neg_1) {
        int numbers [] = {-1, -1};
        EXPECT_EQ(1, GcdFinder::find_max_gcd(numbers, 2));
    }

    TEST_F(Test_GcdFinder, gcd_neg_2_neg_4) {
        int numbers [] = {-2, -4};
        EXPECT_EQ(2, GcdFinder::find_max_gcd(numbers, 2));
    }

    TEST_F(Test_GcdFinder, gcd_neg_20_neg_5) {
        int numbers [] = {-20, -5};
        EXPECT_EQ(5, GcdFinder::find_max_gcd(numbers, 2));
    }

    TEST_F(Test_GcdFinder, gcd_neg_150_neg_50_neg_160) {
        int numbers [] = {-150, -50, -160};
        EXPECT_EQ(50, GcdFinder::find_max_gcd(numbers, 3));
    }

    TEST_F(Test_GcdFinder, gcd_neg_30_6) {
        int numbers [] = {-30, 6};
        EXPECT_EQ(6, GcdFinder::find_max_gcd(numbers, 2));
    }

    TEST_F(Test_GcdFinder, gcd_neg_45_neg_9) {
        int numbers [] = {45, -9};
        EXPECT_EQ(9, GcdFinder::find_max_gcd(numbers, 2));
    }
}
