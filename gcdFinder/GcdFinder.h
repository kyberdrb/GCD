#ifndef GCD_GCDFINDER_H
#define GCD_GCDFINDER_H


#include "../gcdPair/GcdPair.h"

class GcdFinder {
public:
    int find_gcd(const GCD_Pair &pair);
    int find_max_gcd(int* numbers, int numberOfElements);
};


#endif //GCD_GCDFINDER_H
