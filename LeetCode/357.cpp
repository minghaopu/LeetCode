//
//  357.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += f(i);
        }
        return sum;
    }
    int f(int k) {
        if (k == 1) return 10;
        int v = 9;
        for (int i = 1; i < k; i++) {
            v *= (10 - i);
        }
        return v;
    }
};
