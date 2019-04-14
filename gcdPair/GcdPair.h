#ifndef GCD_GCDPAIR_H
#define GCD_GCDPAIR_H


#include "../indexPair/IndexPair.h"

typedef struct gcd_pair {
    int firstNumber;
    int secondNumber;
} GCD_Pair;


GCD_Pair * createGcdPairs(int *numbers, int const & numberOfElements, Index_Pair *index_pairs);


#endif //GCD_GCDPAIR_H
