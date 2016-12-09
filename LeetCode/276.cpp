//
//  276.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (n == 1) return k;
        int f[3] = {k, k * k, 0};
        for (int i = 2; i < n; i++) {
            f[i%3] = f[(i-1)%3] * (k-1) + f[(i-2)%3] * (k - 1);
        }
        return f[(n-1)%3];
    }
};
