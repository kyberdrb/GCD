#include <cstdlib>
#include <iostream>
#include <cstring>
#include "GcdNumber.h"
#include "../utils/Utils.h"
#include "../gcdFinder/GcdFinder.h"
#include <memory>

GCD_Number * createGcdNumbers(const int numberOfElements, const GCD_Pair *gcd_pairs) {
    int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    const int &numberOfAllGcdNumbers = numberOfAllIterations;
    GCD_Number * gcd_numbers = (GCD_Number *) calloc(numberOfAllGcdNumbers, sizeof(GCD_Number));
    for (int i = 0; i < numberOfAllIterations; ++i) {
//        std::cout << gcd_pairs[i].firstNumber << ", " << gcd_pairs[i].secondNumber << std::endl;

        GCD_Number gcd_num;
        std::unique_ptr<GcdFinder> gcdFinder(new GcdFinder());
        gcd_num.value = gcdFinder->find_gcd(gcd_pairs[i]);
        memcpy(&gcd_numbers[i], &gcd_num, sizeof(GCD_Number));
    }

    return gcd_numbers;
}
