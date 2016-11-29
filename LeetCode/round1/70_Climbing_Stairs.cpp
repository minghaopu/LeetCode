//
//  70_Climbing_Stairs.cpp
//  LeetCode
//
//  Created by roneil on 16/5/7.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int climbStairs(int n) {
        vector<int> sums {0, 1, 2};
        for (int i = 3; i <= n; i++) {
            sums[i] = sums[i-1] + sums[i-2];
        }
        return sums[n];
    }
};