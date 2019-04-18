#ifndef GCD_STRINGTONUMBERCONVERTER_H
#define GCD_STRINGTONUMBERCONVERTER_H


class StringToNumberConverter {
private:
    static long convert(const char* numberAsString);

    static void resetErrorNumber();

    static bool isStringNumberValid(const char *numberAsString, const char *endptr, long number);

    static int precomputeNumberOfValidNumbers(char * const *inputArgs, int numberOfArgs);

    static bool isNumberOutOfRange(long number);

    static bool isInputNumberInvalid(long number);

    static bool isInputNumberBlank(const char *numberAsString, const char *endptr);

public:
    static int* createConvertedNumbers(char *const *inputArgs, int &numberOfArgs);
};


#endif //GCD_STRINGTONUMBERCONVERTER_H
