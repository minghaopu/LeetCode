//
//  397.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == 3) return 2;
        if (n == INT_MAX) return 32;
        if ((n & (n - 1)) == 0) return log2(n);
        if ((n & (n + 1)) == 0) return log2(n + 1) + 1;
        if (n & 1) {
            if ((n + 1) % 4 == 0) return integerReplacement((n + 1) / 2) + 2;
            else return integerReplacement((n - 1) / 2) + 2;
        } else return integerReplacement(n / 2) + 1;
    }
    
};
