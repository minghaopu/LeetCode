//
//  26_Remove_Duplicate_from_Sorted_Array.cpp
//  LeetCode
//
//  Created by roneil on 16/5/9.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) count++;
            else nums[i - count] = nums[i];
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }
};
