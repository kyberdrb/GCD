#include <cstdlib>
#include <cstring>
#include <iostream>
#include "NumberPair.h"
#include "../utils/Utils.h"

NumberPair * createNumberPairs(int *numbers, int const &numberOfElements, Index_Pair *index_pairs) {
    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    int const & numberOfGcdPairs = numberOfAllIterations;
    auto* numberPairs = (NumberPair *) calloc((size_t) numberOfGcdPairs, sizeof(NumberPair));
    if (numberPairs == nullptr) {
        std::cout << "Couldn't allocate memory for numberPairs" << std::endl;
        throw std::bad_alloc();
    }

    for (int i = 0; i < numberOfAllIterations; ++i) {
        NumberPair gcd_pair;
        int indexOfFirstNumber = index_pairs[i].indexOfFirstNumber;
        gcd_pair.firstNumber = makeNumberPositive(numbers[indexOfFirstNumber]);
        int indexOfSecondNumber = index_pairs[i].indexOfSecondNumber;
        gcd_pair.secondNumber = abs(numbers[indexOfSecondNumber]);
        memmove(&numberPairs[i], &gcd_pair, sizeof(NumberPair));
    }

    return numberPairs;
}

int makeNumberPositive(const int negativeNumber) {
    return abs(negativeNumber);
}
