//
//  268.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = (int) nums.size(); // n;
        for (int i = 0; i < nums.size(); i++) {
            num ^= i ^ nums[i]; // if i == nums[i] then (num ^= i ^ nums[i]) = 0;
        }
        return num;
    }
};
