#include <cstdlib>
#include <cstring>
#include <iostream>
#include "NumberPair.h"
#include "../utils/Utils.h"

NumberPair* createNumberPairs(int *numbers, int const &numberOfElements, Index_Pair *index_pairs) {
    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    int const & numberOfGcdPairs = numberOfAllIterations;
    auto* numberPairs = (NumberPair *) calloc((size_t) numberOfGcdPairs, sizeof(NumberPair));
    if (numberPairs == nullptr) {
        std::cout << "Couldn't allocate memory for numberPairs" << std::endl;
        throw std::bad_alloc();
    }

    const int &numberOfThreads = numberOfAllIterations;
    pthread_t t[numberOfThreads];
    auto** threadInfoStructs =
            (NumberPairThreadInfo**) calloc((size_t) numberOfThreads, sizeof(NumberPairThreadInfo*));

    for (int i = 0; i < numberOfThreads; ++i) {
        threadInfoStructs[i] = (NumberPairThreadInfo*) calloc(1, sizeof(NumberPairThreadInfo));
        threadInfoStructs[i]->index = i;
        threadInfoStructs[i]->numberPairs = numberPairs;
        threadInfoStructs[i]->index_pairs = index_pairs;
        threadInfoStructs[i]->numbers = numbers;

        pthread_create(&t[i], nullptr, addNumberPair, threadInfoStructs[i]);
    }

    for (int i = 0; i < numberOfThreads; ++i) {
        pthread_join(t[i], nullptr);
        free(threadInfoStructs[i]);
    }
    free(threadInfoStructs);

    return numberPairs;
}

void* addNumberPair(void *additionalDataForThread) {
    auto* threadInfo = (NumberPairThreadInfo*) additionalDataForThread;
    NumberPair numberPair;
    int index = threadInfo->index;

    int indexOfFirstNumber = threadInfo->index_pairs[index].indexOfFirstNumber;
    numberPair.firstNumber = makeNumberPositive(threadInfo->numbers[indexOfFirstNumber]);

    int indexOfSecondNumber = threadInfo->index_pairs[index].indexOfSecondNumber;
    numberPair.secondNumber = abs(threadInfo->numbers[indexOfSecondNumber]);

    memmove(&threadInfo->numberPairs[index], &numberPair, sizeof(NumberPair));

    return nullptr;
}

int makeNumberPositive(const int negativeNumber) {
    return abs(negativeNumber);
}
