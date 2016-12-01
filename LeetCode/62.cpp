//
//  62.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<int> dp(n, 1);
        int left = 1;
        for (int i = 1; i < m; i++) {
            left = 1;
            for (int j = 1; j < n; j++) {
                left = dp[j] + left;
                dp[j] = left;
            }
        }
        return dp[n-1];
    }
};
