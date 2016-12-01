//
//  26.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/30.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int start = 0;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[start]) {
                count++;
            } else {
                swap(nums[i-count], nums[i]);
                start++;
            }
        }
        return start + 1;
    }
};
