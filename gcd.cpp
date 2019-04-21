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

std::unique_ptr<TestRunner> createTestRunner(char*);

int main(int argc, char **argv) {
    std::unique_ptr<TestRunner> testRunner = nullptr;
    try {
        testRunner = createTestRunner(argv[1]);
    } catch (const std::bad_alloc&) {
        std::cout << "Couldn't allocate memory for testRunner" << std::endl;
    }

    if (testRunner->wereAllTestsRun()) {
        return testRunner->getTestStatus();
    }

    try {
        std::unique_ptr<ConvertedNumbers> cleansedNumbers =
                StringToNumberConverter::createConvertedNumbers(argv, argc);

        int maxGcd = GcdFinder::find_max_gcd(
                cleansedNumbers->getConvertedNumbers(),
                cleansedNumbers->getSize() );

        std::cout << maxGcd << std::endl;

    } catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;

        return EXIT_BAD_ALLOC;
    }


    return EXIT_SUCCESS;
}

std::unique_ptr<TestRunner> createTestRunner(char* shouldTestRun) {
    std::unique_ptr<TestRunner> testRunner = nullptr;
    try {
        testRunner = std::unique_ptr<TestRunner>(
                new TestRunner(shouldTestRun)
        );
    } catch (const std::bad_alloc&) {
        throw std::bad_alloc();
    }

    if (testRunner == nullptr) {
        throw std::bad_alloc();
    }

    return testRunner;
}