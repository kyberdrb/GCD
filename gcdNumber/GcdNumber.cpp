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
    auto* gcdNumbers = (GCD_Number *) calloc((size_t) numberOfAllGcdNumbers, sizeof(GCD_Number));
    if (gcdNumbers == nullptr) {
        std::cout << "Couldn't allocate memory for gcdNumbers" << std::endl;
        throw std::bad_alloc();
    }

    const int &num_threads = numberOfAllIterations;
    pthread_t t[num_threads];

    auto** threadInfoStructs = (ThreadInfo**) calloc((size_t) num_threads, sizeof(ThreadInfo*));

    for (int i = 0; i < numberOfAllIterations; ++i) {
        threadInfoStructs[i] = (ThreadInfo*) calloc(1, sizeof(ThreadInfo));
        threadInfoStructs[i]->index = i;
        threadInfoStructs[i]->numberPairs = numberPairs;
        threadInfoStructs[i]->gcdNumbers = gcdNumbers;

        pthread_create(&t[i], nullptr, addGCD, threadInfoStructs[i]);
    }

    for (int i = 0; i < num_threads; ++i) {
        pthread_join(t[i], nullptr);
        free(threadInfoStructs[i]);
    }
    free(threadInfoStructs);

    return gcdNumbers;
}

void* addGCD(void *additionalDataForThread) {
    auto* threadInfo = (ThreadInfo*) additionalDataForThread;
    GCD_Number gcd_num;
    int index = threadInfo->index;

    gcd_num.value = computeGCD(threadInfo->numberPairs[index]);
    memcpy(&threadInfo->gcdNumbers[index], &gcd_num, sizeof(GCD_Number));

    return nullptr;
}

int computeGCD(const NumberPair &pair) {
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
