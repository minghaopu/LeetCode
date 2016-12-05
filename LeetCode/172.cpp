//
//  172.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (long long i = 5; n/i > 0; i *= 5) res += n/i;
        return res;
    }
};
