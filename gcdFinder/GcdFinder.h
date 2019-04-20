#pragma once

#include "../numberPair/NumberPair.h"
#include "../gcdNumber/GcdNumber.h"

class GcdFinder {
private:
    static int find_maximum(int numberOfElements, const gcd_number *gcd_numbers);

public:
    static int find_max_gcd(int* numbers, int numberOfElements);
};
