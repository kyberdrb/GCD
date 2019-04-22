#pragma once

#include "../indexPair/IndexPair.h"

typedef struct numberPair {
    int firstNumber;
    int secondNumber;
} NumberPair;

typedef struct number_pair_thread_info {
    int index;
    Index_Pair* index_pairs;
    NumberPair* numberPairs;
    int* numbers;
} NumberPairThreadInfo;


NumberPair* createNumberPairs(int *numbers, int const &numberOfElements, Index_Pair *index_pairs);

void* addNumberPair(NumberPairThreadInfo* additionalDataForThread);

int makeNumberPositive(int negativeNumber);
