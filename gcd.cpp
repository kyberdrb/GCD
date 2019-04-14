#include <iostream>
#include <cstring>
#include "indexPair/IndexPair.h"
#include "gcdPair/GcdPair.h"
#include "gcdFinder/GcdFinder.h"
#include "gcdNumber/GcdNumber.h"
#include "utils/Utils.h"
#include "testing/testRunner/TestRunner.h"
#include <memory>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    std::unique_ptr<TestRunner> testRunner(new TestRunner(argv[1]));

    if (testRunner->wereAllTestsRun()) {
        return testRunner->getTestStatus();
    }

    // TODO load numbers as arguments from terminal
    const int numberOfElements = 4;
    // TODO check every calloc/malloc/realloc function for null pointer
    int* numbers = (int*) calloc(numberOfElements, sizeof(int));
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;

    std::unique_ptr<GcdFinder> gcdFinder(new GcdFinder());
    int maxGcd = gcdFinder->find_max_gcd(numbers, numberOfElements);

    free(numbers);

    std::cout << maxGcd << std::endl;

    return 0;
}
