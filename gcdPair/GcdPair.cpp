#include <cstdlib>
#include <cstring>
#include "GcdPair.h"
#include "../utils/Utils.h"

GCD_Pair * createGcdPairs(int *numbers, int const & numberOfElements, Index_Pair *index_pairs) {
    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    int const & numberOfGcdPairs = numberOfAllIterations;
    GCD_Pair * gcd_pairs = (GCD_Pair *) calloc(numberOfGcdPairs, sizeof(GCD_Pair));

    for (int i = 0; i < numberOfAllIterations; ++i) {
        GCD_Pair gcd_pair;
        int indexOfFirstNumber = index_pairs[i].indexOfFirstNumber;
        gcd_pair.firstNumber = numbers[indexOfFirstNumber];
        int indexOfSecondNumber = index_pairs[i].indexOfSecondNumber;
        gcd_pair.secondNumber = numbers[indexOfSecondNumber];
        memmove(&gcd_pairs[i], &gcd_pair, sizeof(GCD_Pair));
    }

    return gcd_pairs;
}
