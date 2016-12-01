//
//  27.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/30.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) continue;
            else {
                swap(nums[i], nums[start]);
                start++;
            }
        }
        return start;
    }
};
