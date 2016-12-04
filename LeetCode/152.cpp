//
//  152.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = (int) nums.size();
        int front = 1, back = 1, res = INT_MIN;
        for (int i = 0; i < len; i++) {
            front *= nums[i];
            back *= nums[len - i - 1];
            res = max(res, max(front, back));
            if (front == 0) front = 1;
            if (back == 0) back = 1;
        }
        return res;
    }
};
