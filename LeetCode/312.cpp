//
//  312.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = (int) nums.size() + 2;
        int a[n];
        for (int i = 1; i < n-1; i++) a[i] = nums[i-1];
        a[0] = a[n-1] = 1;
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int left = 0; left + len < n; left++) {
                int right = len + left;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + a[i]*a[left]*a[right]);
                }
            }
        }
        return dp[0][n-1];
    }
};
