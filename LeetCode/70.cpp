//
//  70.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int tmp1 = 1, tmp2 = 2;
        for (int i = 3; i <= n; i++) {
            int val = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = val;
        }
        return tmp2;
    }
};
