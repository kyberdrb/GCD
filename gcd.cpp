#include <iostream>
#include <cstring>
#include "indexPair/IndexPair.h"
#include "numberPair/NumberPair.h"
#include "gcdFinder/GcdFinder.h"
#include "gcdNumber/GcdNumber.h"
#include "utils/Utils.h"
#include "testing/testRunner/TestRunner.h"
#include "stringToNumberConverter/StringToNumberConverter.h"
#include <memory>
#include <gtest/gtest.h>

const int BAD_ALLOC = 1;

int main(int argc, char **argv) {
    std::unique_ptr<TestRunner> testRunner(new TestRunner(argv[1]));

    if (testRunner->wereAllTestsRun()) {
        return testRunner->getTestStatus();
    }

    std::unique_ptr<ConvertedNumbers> numbers = nullptr;

    try {
        numbers = StringToNumberConverter::createConvertedNumbers(argv, argc);
    } catch (std::bad_alloc &e) {
        return BAD_ALLOC;
    }

    int maxGcd = GcdFinder::find_max_gcd(numbers->getConvertedNumbers(), numbers->getSize());
    std::cout << maxGcd << std::endl;

    return EXIT_SUCCESS;
}
