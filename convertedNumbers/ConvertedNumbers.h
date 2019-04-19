#ifndef GCD_CONVERTEDNUMBERS_H
#define GCD_CONVERTEDNUMBERS_H


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


#endif //GCD_CONVERTEDNUMBERS_H
