//
//  115.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = (int) t.length(), l2 = (int) s.length();
        int dp[l1+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= l2; i++) {
            int pre = 1;
            for (int j = 1; j <= l1; j++) {
                int tmp = dp[j];
                dp[j] += (s[i-1] == t[j-1] ? pre : 0);
                pre = tmp;
            }
        }
        return dp[l1];
    }
};
