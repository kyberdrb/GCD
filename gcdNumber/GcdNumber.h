#pragma once

#include "../numberPair/NumberPair.h"

typedef struct gcd_number {
    int value;
} GCD_Number;

typedef struct thread_info {    /* Used as argument to thread_start() */
    int index;
    const NumberPair *numberPairs;
    GCD_Number *gcdNumbers;
} ThreadInfo;

GCD_Number* createGcdNumbers(int numberOfElements, const NumberPair *numberPairs);

void* addGCD(void *additionalDataForThread);

int computeGCD(const NumberPair &pair);
