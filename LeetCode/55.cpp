//
//  55.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPosition = 0;
        int n = (int) nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (maxPosition < i) return false;
            maxPosition = max(maxPosition, nums[i] + i);
            if (maxPosition >= n - 1) return true;
        }
        return true;
    }
};
