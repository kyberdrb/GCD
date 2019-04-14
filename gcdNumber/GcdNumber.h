#ifndef GCD_GCDNUMBER_H
#define GCD_GCDNUMBER_H


#include "../gcdPair/GcdPair.h"

typedef struct gcd_number {
    int value;
} GCD_Number;

GCD_Number * createGcdNumbers(const int numberOfElements, const GCD_Pair *gcd_pairs);


#endif //GCD_GCDNUMBER_H
