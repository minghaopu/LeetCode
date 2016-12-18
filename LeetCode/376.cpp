//
//  376.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = 1;
        int sign = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i] && sign <= 0) {
                len++;
                sign = 1;
            } else if (nums[i-1] > nums[i] && sign >= 0) {
                len++;
                sign = -1;
            }
        }
        return len;
    }
};
