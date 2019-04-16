#include <cstdlib>
#include <cstring>
#include "NumberPair.h"
#include "../utils/Utils.h"

NumberPair * createGcdPairs(int *numbers, int const & numberOfElements, Index_Pair *index_pairs) {
    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    int const & numberOfGcdPairs = numberOfAllIterations;
    NumberPair * gcd_pairs = (NumberPair *) calloc(numberOfGcdPairs, sizeof(NumberPair));

    for (int i = 0; i < numberOfAllIterations; ++i) {
        NumberPair gcd_pair;
        int indexOfFirstNumber = index_pairs[i].indexOfFirstNumber;
        gcd_pair.firstNumber = numbers[indexOfFirstNumber];
        int indexOfSecondNumber = index_pairs[i].indexOfSecondNumber;
        gcd_pair.secondNumber = numbers[indexOfSecondNumber];
        memmove(&gcd_pairs[i], &gcd_pair, sizeof(NumberPair));
    }

    return gcd_pairs;
}
