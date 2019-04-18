#ifndef GCD_NUMBERPAIR_H
#define GCD_NUMBERPAIR_H


#include "../indexPair/IndexPair.h"

typedef struct numberPair {
    int firstNumber;
    int secondNumber;
} NumberPair;


NumberPair * createNumberPairs(int *numbers, int const &numberOfElements, Index_Pair *index_pairs);

int makeNumberPositive(int negativeNumber);

#endif //GCD_NUMBERPAIR_H
