
//
//  228.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        nums.push_back(INT_MAX);
        vector<string> res;
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 1) continue;
            else if (nums[i-1] == pre) {
                res.push_back(to_string(pre));
                pre = nums[i];
            } else {
                res.push_back(to_string(pre) + "->" + to_string(nums[i-1]));
                pre = nums[i];
            }
        }
        return res;
    }
};
