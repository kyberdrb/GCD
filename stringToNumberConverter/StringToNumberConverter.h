#ifndef GCD_STRINGTONUMBERCONVERTER_H
#define GCD_STRINGTONUMBERCONVERTER_H


class StringToNumberConverter {
public:
    static long convert(const char* numberAsString);

    static int* fillWithConvertedNumbers(char *const *argv, const int &numberOfNumbers);
};


#endif //GCD_STRINGTONUMBERCONVERTER_H
