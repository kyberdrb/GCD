#pragma once

#include "../numberPair/NumberPair.h"

class GcdFinder {
public:
    static int find_gcd(const NumberPair &pair);

    static int find_max_gcd(int* numbers, int numberOfElements);
};
