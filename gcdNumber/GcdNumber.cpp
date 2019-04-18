#include <cstdlib>
#include <iostream>
#include <cstring>
#include "GcdNumber.h"
#include "../utils/Utils.h"
#include "../gcdFinder/GcdFinder.h"
#include <memory>

GCD_Number * createGcdNumbers(const int numberOfElements, const NumberPair *numberPairs) {
    int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    const int &numberOfAllGcdNumbers = numberOfAllIterations;
    auto * gcd_numbers = (GCD_Number *) calloc((size_t) numberOfAllGcdNumbers, sizeof(GCD_Number));

    for (int i = 0; i < numberOfAllIterations; ++i) {
        GCD_Number gcd_num;
        gcd_num.value = GcdFinder::find_gcd(numberPairs[i]);
        memcpy(&gcd_numbers[i], &gcd_num, sizeof(GCD_Number));
    }

    return gcd_numbers;
}
