#include <cstdlib>
#include <cstring>
#include "IndexPair.h"
#include "../utils/Utils.h"

Index_Pair * createUniquePairsOfIndexes(const int numberOfElements) {
    if (numberOfElements == 1) {
        Index_Pair * index_pair = (Index_Pair *) calloc(2, sizeof(Index_Pair));
        index_pair->indexOfFirstNumber = 0;
        index_pair->indexOfSecondNumber = 0;
        return index_pair;
    }

    int numberOfAllIterations = computeNumberOfAllIterations(numberOfElements);

    const int indexOfLastElement = numberOfElements - 1;
    int const &numberOfIndexPairs = numberOfAllIterations;
    Index_Pair * index_pairs = (Index_Pair *) calloc(numberOfIndexPairs, sizeof(Index_Pair));
    int i = 0;
    int j = 0;
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
