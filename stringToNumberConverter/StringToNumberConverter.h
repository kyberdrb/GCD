#pragma once

#include "../convertedNumbers/ConvertedNumbers.h"
#include <memory>

class StringToNumberConverter {
private:
    static long convert(const char* numberAsString);

    static void resetErrorNumber();

    static bool isStringNumberValid(const char *numberAsString, const char *residualString, long number);

    static int precomputeNumberOfValidNumbers(char * const *inputArgs, int numberOfArgs);

    static bool isNumberOutOfRange(long number);

    static bool isInputNumberInvalid(long number);

    static bool isInputNumberBlank(const char *numberAsString, const char *residualString);

public:
    static std::unique_ptr<ConvertedNumbers> createConvertedNumbers(char *const *inputArgs, int numberOfArgs);
};
