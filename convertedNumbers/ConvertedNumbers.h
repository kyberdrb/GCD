#pragma once

class ConvertedNumbers {
private:
    int* convertedNumbers;
    int size;

public:
    ConvertedNumbers(int *convertedNumbers, int size);

    int* getConvertedNumbers() const;

    int getSize() const;

    ~ConvertedNumbers();
};
