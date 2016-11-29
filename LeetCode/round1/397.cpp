//
//  397.cpp
//  LeetCode
//
//  Created by roneil on 9/20/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int integerReplacement(int n) {
        return getTimes(n, 0);
    }
    int getTimes(int n, int depth) {
        if (n == 1) return 0;
        if (n % 2 == 0) return getTimes(n/2, depth + 1);
        else {
            return min(getTimes(n + 1, depth + 1), getTimes(n - 1, depth + 1));
        }
    }
};
