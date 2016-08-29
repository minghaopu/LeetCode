//
//  231.cpp
//  LeetCode
//
//  Created by roneil on 8/27/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//
#include "Header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //return n <= 0 ? false : (n == pow(2, round(log10(n) / log10(2))));
        return n > 0 && !(n&(n-1));
//        return n>0 && n==(n&-n);

    }
};
