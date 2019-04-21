#pragma once

#include "../numberPair/NumberPair.h"

typedef struct gcd_number {
    int value;
} GCD_Number;

typedef struct thread_info {    /* Used as argument to thread_start() */
    int thread_num;
} ThreadInfo;

GCD_Number* createGcdNumbers(int numberOfElements, const NumberPair *numberPairs);

void* call_from_thread(void* additionalDataForThread);

int find_gcd(const NumberPair &pair);
