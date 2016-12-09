//
//  231_326_342.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n-1)) && !((n-1) % 3);
    }
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1) == 0;
    }
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};
