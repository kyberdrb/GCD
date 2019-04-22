#include <cstdlib>
#include <cstring>
#include <iostream>
#include "IndexPair.h"
#include "../utils/Utils.h"

Index_Pair * createUniquePairsOfIndexes(const int numberOfElements) {
    if (numberOfElements == 1) {
        auto * index_pair = (Index_Pair *) calloc(2, sizeof(Index_Pair));
        if (index_pair == nullptr) {
            std::cout << "Couldn't allocate memory for index_pair" << std::endl;
            throw std::bad_alloc();
        }

        index_pair->indexOfFirstNumber = 0;
        index_pair->indexOfSecondNumber = 0;
        return index_pair;
    }

    int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);

    const int indexOfLastElement = numberOfElements - 1;
    int const &numberOfIndexPairs = numberOfAllIterations;
    auto * index_pairs = (Index_Pair *) calloc((size_t) numberOfIndexPairs, sizeof(Index_Pair));
    if (index_pairs == nullptr) {
        std::cout << "Couldn't allocate memory for index_pairs" << std::endl;
        throw std::bad_alloc();
    }

    int i = 0;
    int j = 0;

    // TODO parallelize this "for" loop
    for (int iteration = 0; iteration < numberOfAllIterations;) {
        if (i == j) {
            j++;
            continue;
        }

        Index_Pair index_pair;
        index_pair.indexOfFirstNumber = i;
        index_pair.indexOfSecondNumber = j;
        memmove(&index_pairs[iteration], &index_pair, sizeof(Index_Pair));

        if (j == indexOfLastElement) {
            i++;
            j = i;
        } else {
            j++;
        }

        iteration++;
    }
    return index_pairs;
}
