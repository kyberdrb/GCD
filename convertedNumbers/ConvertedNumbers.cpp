#include <malloc.h>
#include "ConvertedNumbers.h"

ConvertedNumbers::ConvertedNumbers(
        int *convertedNumbers,
        int size)
        :
        convertedNumbers(convertedNumbers),
        size(size)
        {}

int *ConvertedNumbers::getConvertedNumbers() const {
    return convertedNumbers;
}

int ConvertedNumbers::getSize() const {
    return size;
}

ConvertedNumbers::~ConvertedNumbers() {
    if (convertedNumbers != nullptr) {
        free(convertedNumbers);
    }
}
