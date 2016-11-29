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
    int rob_method2(vector<int>& nums) {
        int n = nums.size();
        int pre = 0, cur = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};
