#ifndef GCD_INDEXPAIR_H
#define GCD_INDEXPAIR_H


typedef struct index_pair {
    int indexOfFirstNumber;
    int indexOfSecondNumber;
} Index_Pair;

Index_Pair * createUniquePairsOfIndexes(int numberOfElements);


#endif //GCD_INDEXPAIR_H
