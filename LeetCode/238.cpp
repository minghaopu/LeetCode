//
//  238.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = (int) nums.size();
        vector<int> left(l,1);
        vector<int> right(l,1);
        for (int i = 1; i < l; i++) left[i] = left[i-1] * nums[i-1];
        for (int i = l - 2; i > -1; i--) {
            right[i] = right[i+1] * nums[i+1];
            left[i] *= right[i];
        }
        return left;
        
    }
};
