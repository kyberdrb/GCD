#ifndef GCD_GCDFINDER_H
#define GCD_GCDFINDER_H


#include "../numberPair/NumberPair.h"

class GcdFinder {
public:
    static int find_gcd(const NumberPair &pair);

    static int find_max_gcd(int* numbers, int numberOfElements);
};


#endif //GCD_GCDFINDER_H
