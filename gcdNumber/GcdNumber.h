#ifndef GCD_GCDNUMBER_H
#define GCD_GCDNUMBER_H


#include "../numberPair/NumberPair.h"

typedef struct gcd_number {
    int value;
} GCD_Number;

GCD_Number * createGcdNumbers(const int numberOfElements, const NumberPair *numberPairs);


#endif //GCD_GCDNUMBER_H
