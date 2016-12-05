//
//  209.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = INT_MAX, start = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                len = min(len, i - start + 1);
                sum -= nums[start++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
