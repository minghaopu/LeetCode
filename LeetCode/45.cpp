//
//  45.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int curMax = 0, nextMax = 0, i = 0, level = 0, n = (int)nums.size();
        while (curMax - i >= 0) {
            level++;
            while (i <= curMax) {
                nextMax = max(nextMax, i + nums[i]);
                if (nextMax >= n - 1) return level;
                i++;
            }
            curMax = nextMax;
        }
        return 0;
        
    }
};
