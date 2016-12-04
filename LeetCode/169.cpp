//
//  169.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                n = nums[i];
                count++;
            } else if (n == nums[i]) count++;
            else count--;
        }
        return n;
    }
};
