//
//  78_90.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int> ());
        for (int i = 0; i < nums.size(); i++) {
            int n = (int)res.size();
            for (int j = 0; j < n; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int start, size = 0;
        vector<vector<int>> res(1, vector<int> ());
        for (int i = 0; i < n; i++) {
            start = i > 0 && nums[i] == nums[i-1] ? size : 0;
            size = (int)res.size();
            for (int j = start; j < size; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
