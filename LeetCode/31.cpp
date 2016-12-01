//
//  31.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = (int)nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        reverse(nums.begin() + i + 1, nums.end());
        if (i == -1) return;
        int index = i + 1;
        while (index < nums.size() && nums[index] <= nums[i]) index++;
        swap(nums[index], nums[i]);
    }
};
