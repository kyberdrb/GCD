#pragma once

#include "../numberPair/NumberPair.h"

typedef struct gcd_number {
    int value;
} GCD_Number;

typedef struct gcd_number_thread_info {
    int index;
    const NumberPair *numberPairs;
    GCD_Number *gcdNumbers;
} GcdNumberThreadInfo;

GCD_Number* createGcdNumbers(int numberOfElements, const NumberPair *numberPairs);

void* addGCD(void *additionalDataForThread);

int computeGCD(const NumberPair &pair);
