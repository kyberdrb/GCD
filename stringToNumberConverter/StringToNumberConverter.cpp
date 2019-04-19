#include<cstdlib>
#include <iosfwd>
#include <string>
#include <climits>
#include <stdexcept>
#include <iostream>
#include "StringToNumberConverter.h"
#include "../convertedNumbers/ConvertedNumbers.h"

long StringToNumberConverter::convert(const char *numberAsString) {
    char *residualString = nullptr;
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

bool StringToNumberConverter::isStringNumberValid(const char *numberAsString, const char *residualString, long number) {
    return    isNumberOutOfRange(number)
           || isInputNumberInvalid(number)
           || isInputNumberBlank(numberAsString, residualString);
}

bool StringToNumberConverter::isNumberOutOfRange(long number) {
    return (errno == ERANGE && (number == LONG_MAX || number == LONG_MIN));
}

bool StringToNumberConverter::isInputNumberInvalid(long number) { return (errno != 0 && number == 0); }

bool StringToNumberConverter::isInputNumberBlank(const char *numberAsString, const char *residualString) {
    return numberAsString == residualString;
}

std::unique_ptr<ConvertedNumbers> StringToNumberConverter::createConvertedNumbers(char *const *inputArgs, int numberOfArgs) {
    int numberOfValidNumbers = precomputeNumberOfValidNumbers(inputArgs, numberOfArgs);

    // TODO IN-PROGRESS check every calloc/malloc/realloc function for null pointer
    //  and catch std::bad_alloc after "new" allocation
    //  then throw an exception -> handle the exception in main

    // TODO delegate the creation of "int* numbers" on ConvertedNumbers
    //  and pass only the "size" parameter to the constructor - the
    //  constructor will then allocate space for the array
    int* numbers = (int *) calloc((size_t) numberOfValidNumbers, sizeof(int));
    if (numbers == nullptr) {
        std::cout << "Couldn't allocate an array of coverted numbers" << std::endl;
        throw std::bad_alloc();
    }

    int currentIndexOfValidNumber = 0;
    for (int i = 0; i < numberOfArgs; i++) {
        const char* numberAsString = inputArgs[i];

        try {
            numbers[currentIndexOfValidNumber] = StringToNumberConverter::convert(numberAsString);
            currentIndexOfValidNumber++;
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }

    std::unique_ptr<ConvertedNumbers> convertedNumbers (
            new ConvertedNumbers(numbers, numberOfValidNumbers)
    );

    return convertedNumbers;
}

int StringToNumberConverter::precomputeNumberOfValidNumbers(char *const *inputArgs, const int numberOfArgs) {
    int numberOfValidNumbers = 0;

    for (int i = 0; i < numberOfArgs; i++) {
        try {
            StringToNumberConverter::convert(inputArgs[i]);
            numberOfValidNumbers++;
        } catch (const std::invalid_argument &e) {
            continue;
        }
    }

    return numberOfValidNumbers;
}
