//
//  377.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution_TLE {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        dfs(nums, target, count);
        return count;
    }
    void dfs(vector<int>& nums, int target, int& count) {
        if (target == 0) {
            count++;
            return;
        }
        for (int n : nums) {
            if (n > target) return;
            dfs(nums, target - n, count);
        }
    }
};
class SolutionI {// O(target * n) + O(n*logn)
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1];
        memset(dp, 0, sizeof(int) * (target + 1));
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (n > i) break;
                // if (n > i) continue;
                else if (n == i) dp[i] += 1;
                else dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};

class SolutionII {// O(target * n)
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1];
        memset(dp, 0, sizeof(int) * (target + 1));
//        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
//                if (n > i) break;
                if (n > i) continue;
                else if (n == i) dp[i] += 1;
                else dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};
