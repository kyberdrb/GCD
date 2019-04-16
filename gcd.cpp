#include <iostream>
#include <cstring>
#include "indexPair/IndexPair.h"
#include "gcdPair/GcdPair.h"
#include "gcdFinder/GcdFinder.h"
#include "gcdNumber/GcdNumber.h"
#include "utils/Utils.h"
#include "testing/testRunner/TestRunner.h"
#include "stringToNumberConverter/StringToNumberConverter.h"
#include <memory>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    std::unique_ptr<TestRunner> testRunner(new TestRunner(argv[1]));

    if (testRunner->wereAllTestsRun()) {
        return testRunner->getTestStatus();
    }

    const int numberOfNumbers = argc;
    int* numbers = StringToNumberConverter::fillWithConvertedNumbers(argv, numberOfNumbers);

    std::unique_ptr<GcdFinder> gcdFinder(new GcdFinder());
    int maxGcd = gcdFinder->find_max_gcd(numbers, numberOfNumbers);

    free(numbers);

    std::cout << maxGcd << std::endl;

    return 0;
}
