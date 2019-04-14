#include "Utils.h"

int computeNumberOfAllIterations(const int numberOfElements) {
    if (numberOfElements == 1) {
        return 1;
    }

    int const &numberOfDuplicates = numberOfElements;
    int const &lastElement = numberOfElements;
    const int numberOfAllIterations =
            (numberOfElements * (1 + lastElement)) / 2 - numberOfDuplicates;
    return numberOfAllIterations;
}
