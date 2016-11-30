//
//  18.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int>> res;
        int l, r, sum, size = (int)nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < size - 2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                l = j + 1;
                r = size - 1;
                while (l < r) {
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum > target) r--;
                    else if (sum < target) l++;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) l++;
                        l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
