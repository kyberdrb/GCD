#include <cstdlib>
#include <iostream>
#include <cstring>
#include "GcdNumber.h"
#include "../utils/Utils.h"
#include "../gcdFinder/GcdFinder.h"
#include <memory>

GCD_Number* createGcdNumbers(const int numberOfElements, const NumberPair *numberPairs) {
    int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    const int &numberOfAllGcdNumbers = numberOfAllIterations;
    auto* gcd_numbers = (GCD_Number *) calloc((size_t) numberOfAllGcdNumbers, sizeof(GCD_Number));
    if (gcd_numbers == nullptr) {
        std::cout << "Couldn't allocate memory for gcd_numbers" << std::endl;
        throw std::bad_alloc();
    }

    for (int i = 0; i < numberOfAllIterations; ++i) {
        GCD_Number gcd_num;
        gcd_num.value = find_gcd(numberPairs[i]);
        memcpy(&gcd_numbers[i], &gcd_num, sizeof(GCD_Number));
    }

    return gcd_numbers;
}

int find_gcd(const NumberPair &pair) {
    const int firstNumber = pair.firstNumber;
    const int secondNumber = pair.secondNumber;

    if (firstNumber == 0 || secondNumber == 0) {
        return 0;
    }

    if (firstNumber == secondNumber) {
        return firstNumber;
    }

    int greaterNum = firstNumber;
    int lesserNum = secondNumber;


    if (secondNumber > firstNumber) {
        greaterNum = secondNumber;
        lesserNum = firstNumber;
    }

    int remainder = 1;
    int gcd;
    while (remainder != 0) {
        remainder = greaterNum % lesserNum;
        greaterNum = lesserNum;
        lesserNum = remainder;
    }

    gcd = greaterNum;
    return gcd;
}
