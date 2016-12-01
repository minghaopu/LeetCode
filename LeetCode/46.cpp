//
//  46.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& nums, int start) {
        if (start == nums.size()) res.push_back(nums);
        else {
            for (int i = start; i < nums.size(); i++) {
                swap(nums[start], nums[i]);
                helper(res, nums, start + 1);
                swap(nums[start], nums[i]);
            }
        }
    }
};
