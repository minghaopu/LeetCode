//
//  312. Burst Balloons.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/24.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    map<vector<int>, int> cache;
public:
    int maxCoins(vector<int>& nums) {
        int sz = int(nums.size());
        int n = sz + 2;
        int A[n];
        for (int i = 1; i <= sz; i++) {
            A[i] = nums[i-1];
        }
        A[0] = A[sz+1] = 1;
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) dp[i][j] = 0;
        }
        for (int l = 2; l < n; l++) {
            for (int left = 0; left < n - l; left++) {
                int right = left + l;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right], A[left] * A[right] * A[i] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n-1];
    }
};
