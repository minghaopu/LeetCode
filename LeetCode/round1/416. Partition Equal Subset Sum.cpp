//
//  416. Partition Equal Subset Sum.cpp
//  LeetCode
//
//  Created by roneil on 11/19/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    // TLE - DFS
    bool canPartition_dfs(vector<int>& nums) {
        int sum = 0;
        for (int n: nums) sum += n;
        if (sum & 1) return false;
        sort(nums.begin(), nums.end());
        int half = sum / 2;
        return dfs_416(nums, 0, half);
    }
    bool dfs_416(vector<int>& nums, int start, int sum) {
        if (sum == 0) return true;
        if (sum < 0) return false;
        for (int i = start; i < nums.size(); i++) {
            if (dfs_416(nums, i + 1, sum - nums[i])) return true;
        }
        return false;
    }
    
    // DP
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n: nums) sum += n;
        if (sum & 1) return false;
        int half = sum / 2;
        bool dp[half + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = half; j >= nums[i-1]; j--) {
                dp[j] = dp[j] || dp[j - nums[i-1]];
            }
        }
        return dp[half];
    }
};
