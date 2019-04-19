#pragma once

typedef struct index_pair {
    int indexOfFirstNumber;
    int indexOfSecondNumber;
} Index_Pair;

Index_Pair * createUniquePairsOfIndexes(int numberOfElements);
