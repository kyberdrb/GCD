#ifndef GCD_NUMBERPAIR_H
#define GCD_NUMBERPAIR_H


#include "../indexPair/IndexPair.h"

// TODO rename from `GcdPair` and its files to `NumberPair`
typedef struct numberPair {
    int firstNumber;
    int secondNumber;
} NumberPair;


NumberPair * createNumberPairs(int *numbers, int const &numberOfElements, Index_Pair *index_pairs);

int makeNumberPositive(const int negativeNumber);

#endif //GCD_NUMBERPAIR_H
