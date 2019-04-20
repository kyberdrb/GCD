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

const int EXIT_BAD_ALLOC = 1;

int main(int argc, char **argv) {
    std::unique_ptr<TestRunner> testRunner(new TestRunner(argv[1]));

    if (testRunner->wereAllTestsRun()) {
        return testRunner->getTestStatus();
    }

    try {
        std::unique_ptr<ConvertedNumbers> numbers = StringToNumberConverter::createConvertedNumbers(argv, argc);
        int maxGcd = GcdFinder::find_max_gcd(numbers->getConvertedNumbers(), numbers->getSize());
        std::cout << maxGcd << std::endl;
    } catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
        return EXIT_BAD_ALLOC;
    }


    return EXIT_SUCCESS;
}
