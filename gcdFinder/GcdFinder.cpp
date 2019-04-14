#include <cstdlib>
#include <iostream>
#include <cstring>
#include "GcdFinder.h"
#include "../gcdNumber/GcdNumber.h"
#include "../utils/Utils.h"

// TODO try to make the for loops in methods parallel
int GcdFinder::find_max_gcd(int *numbers, int numberOfElements) {
    Index_Pair *index_pairs = createUniquePairsOfIndexes(numberOfElements);

    GCD_Pair *gcd_pairs = createGcdPairs(numbers, numberOfElements, index_pairs);
    free(index_pairs);

    GCD_Number *gcd_numbers = createGcdNumbers(numberOfElements, gcd_pairs);
    free(gcd_pairs);

    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    int maxGcd = 0;
    for (int i = 0; i < numberOfAllIterations; ++i) {
        if (gcd_numbers[i].value > maxGcd) {
            maxGcd = gcd_numbers[i].value;
        }
    }

    free(gcd_numbers);
    return maxGcd;
}

int GcdFinder::find_gcd(const GCD_Pair &pair) {
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
    int gcd = 1;
    while (remainder != 0) {
        remainder = greaterNum % lesserNum;
        greaterNum = lesserNum;
        lesserNum = remainder;
    }

    gcd = greaterNum;
    return gcd;
}