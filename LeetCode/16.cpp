//
//  16.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX;
        int ans = 0;
        int len = nums.size();
        int sum, l, r;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            l = i + 1; r = len - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum > target) r--;
                else if (sum < target) l++;
                else return sum;
                
                if (minDiff > abs(sum - target)) {
                    minDiff = abs(sum - target);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};
