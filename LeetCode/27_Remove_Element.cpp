//
//  27_Remove_Element.cpp
//  LeetCode
//
//  Created by roneil on 16/5/8.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = nums.size() - 1, i = 0;
        while (i <= l) {
            if (nums[i] != val) i++;
            else {
                nums[i] = nums[l];
                nums.pop_back();
                l--;
            }
        }
        return nums.size();
    }
};