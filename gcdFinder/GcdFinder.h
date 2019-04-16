#ifndef GCD_GCDFINDER_H
#define GCD_GCDFINDER_H


#include "../numberPair/NumberPair.h"

class GcdFinder {
public:
    int find_gcd(const NumberPair &pair);
    int find_max_gcd(int* numbers, int numberOfElements);
};


#endif //GCD_GCDFINDER_H
