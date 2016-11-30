//
//  15.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = len - 1, rest = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] > rest) r--;
                else if (nums[l] + nums[r] < rest) l++;
                else {
                    res.push_back({nums[i],nums[l],nums[r]});
                    while (nums[l] == nums[l+1]) l++;
                    l++;
                    while (nums[r] == nums[r-1]) r--;
                    r--;
                }
            }
        }
        return res;
    }
};
