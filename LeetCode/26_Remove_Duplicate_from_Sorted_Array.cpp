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
        int l = nums.size(), i = 1, j = 0;
        if (l < 2) return l;
        while (i < nums.size()) {
            if (nums[i] != nums[i-1]) {
                if (i != j+1) nums.erase(nums.begin()+j, nums.begin()+i-1);
                j++;
                i = j+1;
            }else {
                if (i == nums.size()-1) nums.erase(nums.begin()+j, nums.begin()+i);
                i++;
            }
        }
        return nums.size();
    }
};