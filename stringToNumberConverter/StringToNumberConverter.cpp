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

std::unique_ptr<ConvertedNumbers> StringToNumberConverter::createConvertedNumbers(
        char *const *inputArgs,
        int numberOfArgs)
{
    // TODO instead of losing time with precomputing valid values
    //  a more intelligent data structure like ArrayList/vector would be
    //  more appropriate
    int numberOfValidNumbers = precomputeNumberOfValidNumbers(inputArgs, numberOfArgs);

    int* validNumbers = (int *) calloc((size_t) numberOfValidNumbers, sizeof(int));
    if (validNumbers == nullptr) {
        std::cout << "Couldn't allocate memory for an array of coverted validNumbers" << std::endl;
        throw std::bad_alloc();
    }

    int currentIndexOfValidNumber = 0;
    // TODO parallelize this "for" loop
    //  but after changing "validNumbers" from "int*"
    //  to std::vector
    for (int i = 0; i < numberOfArgs; i++) {
        const char* numberAsString = inputArgs[i];

        try {
            // TODO Values of type 'long' may not fit into the receiver type 'int';
            //  change everything in the program that works with array of numbers
            //  to array of longs
            validNumbers[currentIndexOfValidNumber] = StringToNumberConverter::convert(numberAsString);
            currentIndexOfValidNumber++;
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }

    std::unique_ptr<ConvertedNumbers> convertedNumbers = nullptr;
    try {
        convertedNumbers = createInstanceOfConvertedNumbers(validNumbers, numberOfValidNumbers);
    } catch (const std::bad_alloc&) {
        std::cout << "Couldn't allocate memory for convertedNumbers" << std::endl;
        throw std::bad_alloc();
    }

    return convertedNumbers;
}

int StringToNumberConverter::precomputeNumberOfValidNumbers(char *const *inputArgs, int numberOfArgs) {
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

std::unique_ptr<ConvertedNumbers>
StringToNumberConverter::createInstanceOfConvertedNumbers(
        int *numbers,
        int numberOfValidNumbers)
{
    std::unique_ptr<ConvertedNumbers> convertedNumbers = nullptr;

    try {
        convertedNumbers = std::unique_ptr<ConvertedNumbers>(
                new ConvertedNumbers(numbers, numberOfValidNumbers)
        );
    } catch (const std::bad_alloc&) {
        throw std::bad_alloc();
    }

    if (convertedNumbers == nullptr) {
        throw std::bad_alloc();
    }

    return convertedNumbers;
}
