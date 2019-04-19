#pragma once

#include "../numberPair/NumberPair.h"

typedef struct gcd_number {
    int value;
} GCD_Number;

GCD_Number * createGcdNumbers(int numberOfElements, const NumberPair *numberPairs);
