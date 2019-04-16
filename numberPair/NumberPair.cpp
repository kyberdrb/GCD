#include <cstdlib>
#include <cstring>
#include "NumberPair.h"
#include "../utils/Utils.h"

NumberPair * createNumberPairs(int *numbers, int const &numberOfElements, Index_Pair *index_pairs) {
    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    int const & numberOfGcdPairs = numberOfAllIterations;
    NumberPair * numberPairs = (NumberPair *) calloc(numberOfGcdPairs, sizeof(NumberPair));

    for (int i = 0; i < numberOfAllIterations; ++i) {
        NumberPair gcd_pair;
        int indexOfFirstNumber = index_pairs[i].indexOfFirstNumber;
        gcd_pair.firstNumber = numbers[indexOfFirstNumber];
        int indexOfSecondNumber = index_pairs[i].indexOfSecondNumber;
        gcd_pair.secondNumber = numbers[indexOfSecondNumber];
        memmove(&numberPairs[i], &gcd_pair, sizeof(NumberPair));
    }

    return numberPairs;
}
