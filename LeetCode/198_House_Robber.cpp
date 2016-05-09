//
//  198_House_Robber.cpp
//  LeetCode
//
//  Created by roneil on 16/5/9.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> sums {0, nums[0]};
        int l = nums.size();
        for (int index = 2; index <= l; index++) {
            sums.push_back(max(sums[index-1], sums[index-2] + nums[index-1]));
        }
        return sums[l];
    }
};