#include <cstdlib>
#include <iostream>
#include <cstring>
#include "GcdFinder.h"
#include "../gcdNumber/GcdNumber.h"
#include "../utils/Utils.h"

// TODO try to make every "for" loop in the program parallel
int GcdFinder::find_max_gcd(int *numbers, int numberOfElements) {
    int maxGcd = 0;
    try {
        Index_Pair *index_pairs = createUniquePairsOfIndexes(numberOfElements);

        NumberPair *numberPairs = createNumberPairs(numbers, numberOfElements, index_pairs);
        free(index_pairs);

        GCD_Number *gcd_numbers = createGcdNumbers(numberOfElements, numberPairs);
        free(numberPairs);

        maxGcd = find_maximum(numberOfElements, gcd_numbers);
        free(gcd_numbers);
    } catch (std::bad_alloc &e) {
        std::cout << "Couldn't allocate memory inside \"find_max_gcd\"" << std::endl;
        throw std::bad_alloc();
    }

    return maxGcd;
}

int GcdFinder::find_maximum(int numberOfElements, const GCD_Number *gcd_numbers) {
    int maximum = 0;
    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    for (int i = 0; i < numberOfAllIterations; ++i) {
        if (gcd_numbers[i].value > maximum) {
            maximum = gcd_numbers[i].value;
        }
    }
    return maximum;
}