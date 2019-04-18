#include <cstdlib>
#include <iosfwd>
#include <string>
#include <climits>
#include <stdexcept>
#include <iostream>
#include "StringToNumberConverter.h"

long StringToNumberConverter::convert(const char *numberAsString) {
    char *residualString;
    resetErrorNumber();
    long number = std::strtol(numberAsString, &residualString, 10);

    if (isStringNumberValid(numberAsString, residualString, number)) {
        throw std::invalid_argument("String is not a valid number");
    }

    return number;
}

void StringToNumberConverter::resetErrorNumber() {
    errno = 0;
}

bool StringToNumberConverter::isStringNumberValid(const char *numberAsString, const char *endptr, long number) {
    return    isNumberOutOfRange(number)
           || isInputNumberInvalid(number)
           || isInputNumberBlank(numberAsString, endptr);
}

bool StringToNumberConverter::isNumberOutOfRange(long number) {
    return (errno == ERANGE && (number == LONG_MAX || number == LONG_MIN));
}

bool StringToNumberConverter::isInputNumberInvalid(long number) { return (errno != 0 && number == 0); }

bool StringToNumberConverter::isInputNumberBlank(const char *numberAsString, const char *endptr) {
    return numberAsString == endptr;
}

// TODO make method createConvertedNumbers return unique pointer to ConvertedNumbers
//  in order to remove "free" statement in main
// TODO make test cases for method createConvertedNumbers
int* StringToNumberConverter::createConvertedNumbers(char *const *inputArgs, int &numberOfArgs) {
    int numberOfValidNumbers = precomputeNumberOfValidNumbers(inputArgs, numberOfArgs);

    // TODO check every calloc/malloc/realloc function for null pointer
    //  then throw an exception -> handle the exception in main
    int* numbers = (int *) calloc((size_t) numberOfValidNumbers, sizeof(int));

    for (int i = 1; i <= numberOfValidNumbers; i++) {
        const char* numberAsString = inputArgs[i];

        try {
            numbers[i - 1] = StringToNumberConverter::convert(numberAsString);
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }

    return numbers;
}

int StringToNumberConverter::precomputeNumberOfValidNumbers(char *const *inputArgs, const int numberOfArgs) {
    int numberOfValidNumbers = 0;

    for (int i = 1; i < numberOfArgs; i++) {
        try {
            StringToNumberConverter::convert(inputArgs[i]);
            numberOfValidNumbers++;
        } catch (const std::invalid_argument &e) {
            continue;
        }
    }

    return numberOfValidNumbers;
}
