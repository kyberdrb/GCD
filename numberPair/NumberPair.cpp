#include <cstdlib>
#include <cstring>
#include <iostream>
#include "NumberPair.h"
#include "../utils/Utils.h"
#include <thread>

NumberPair* createNumberPairs(int *numbers, int const &numberOfElements, Index_Pair *index_pairs) {
    const int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);
    int const & numberOfGcdPairs = numberOfAllIterations;
    auto* numberPairs = (NumberPair *) calloc((size_t) numberOfGcdPairs, sizeof(NumberPair));
    if (numberPairs == nullptr) {
        std::cout << "Couldn't allocate memory for numberPairs" << std::endl;
        throw std::bad_alloc();
    }

    const int &numberOfThreads = numberOfAllIterations;

    std::thread threads[numberOfThreads];
    auto** threadInfoStructs =
            (NumberPairThreadInfo**) calloc((size_t) numberOfThreads, sizeof(NumberPairThreadInfo*));

    for (int i = 0; i < numberOfThreads; ++i) {
        threadInfoStructs[i] = (NumberPairThreadInfo*) calloc(1, sizeof(NumberPairThreadInfo));
        threadInfoStructs[i]->index = i;
        threadInfoStructs[i]->numberPairs = numberPairs;
        threadInfoStructs[i]->index_pairs = index_pairs;
        threadInfoStructs[i]->numbers = numbers;

        threads[i] = std::thread(addNumberPair, threadInfoStructs[i]);
    }

    for (int i = 0; i < numberOfThreads; ++i) {
        threads[i].join();
        free(threadInfoStructs[i]);
    }
    free(threadInfoStructs);

    return numberPairs;
}

void* addNumberPair(NumberPairThreadInfo* additionalDataForThread) {
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
