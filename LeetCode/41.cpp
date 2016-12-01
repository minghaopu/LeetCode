//
//  41.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] == i+1 || nums[i] <= 0 || nums[i] > n || nums[nums[i] - 1] == nums[i]) i++;
            else swap(nums[i], nums[nums[i] - 1]);
        }
        for (i = 0; i < n; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return n + 1;
    }
};
