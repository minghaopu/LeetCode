//
//  368.cpp
//  LeetCode
//
//  Created by neal on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = (int) nums.size();
        vector<int> res;
        vector<int> dp(size, 1);
        vector<int> pre(size, -1);
        sort(nums.begin(), nums.end());
        int length = 0, index = -1;
        for (int i = 0; i < size; i++) {
            for (int j = i-1; j > -1; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1> dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (dp[i] > length) {
                length = dp[i];
                index = i;
            }
        }
        
        while (index != -1) {
            res.push_back(nums[index]);
            index = pre[index];
        }
        return res;
    }
};
