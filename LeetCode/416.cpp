//
//  416.cpp
//  LeetCode
//
//  Created by neal on 12/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum >> 1;
        int dp[target + 1];
        fill_n(&dp[0], target+1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = target; i >= n; i--) dp[i] = dp[i] || dp[i-n];
            // for (int i = n; i <= target; i++) dp[i] = dp[i] || dp[i-n];
            for (int i = 0; i <= target; i++) cout<<dp[i];
            cout<<endl;
        }
        return dp[target];
    }
};
