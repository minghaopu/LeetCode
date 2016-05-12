//
//  172_Factorial_Trailing_Zeroes.cpp
//  LeetCode
//
//  Created by roneil on 16/5/11.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int r = 0;
        while (n > 4) {
            n = floor(n/5);
            r += n;
        }
        return r;
    }
};