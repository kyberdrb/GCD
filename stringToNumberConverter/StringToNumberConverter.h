#ifndef GCD_STRINGTONUMBERCONVERTER_H
#define GCD_STRINGTONUMBERCONVERTER_H


class StringToNumberConverter {
private:
    static void resetErrorNumber();

    static bool isStringNumberValid(const char *numberAsString, const char *endptr, long number);

    static int precomputeNumberOfValidNumbers(char * const *inputArgs, const int numberOfArgs);

    static bool isNumberOutOfRange(long number);

    static bool isInputNumberInvalid(long number);

    static bool isInputNumberBlank(const char *numberAsString, const char *endptr);

public:
    static long convert(const char* numberAsString);

    static int* createConvertedNumbers(char *const *inputArgs, int &numberOfArgs);
};


#endif //GCD_STRINGTONUMBERCONVERTER_H
