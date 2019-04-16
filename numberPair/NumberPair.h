#ifndef GCD_NUMBERPAIR_H
#define GCD_NUMBERPAIR_H


#include "../indexPair/IndexPair.h"

// TODO rename from `GcdPair` and its files to `NumberPair`
typedef struct numberPair {
    int firstNumber;
    int secondNumber;
} NumberPair;


NumberPair * createGcdPairs(int *numbers, int const & numberOfElements, Index_Pair *index_pairs);


#endif //GCD_NUMBERPAIR_H
