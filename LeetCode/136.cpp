//
//  136.cpp
//  LeetCode
//
//  Created by roneil on 9/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
//    Given an array of integers, every element appears twice except for one. Find that single one.
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        for (int i = 1; i < nums.size(); i++) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
//  Given an array of integers, every element appears three times except for one. Find that single one.
    
    int singleNumber2(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (int n : nums) {
            ones =(ones ^ n) & ~twos;
            twos =(twos ^ n) & ~ones;
        }
        return ones;
    }
//    Given an array of numbers nums, in which exactly two elements appear only once
//    and all the other elements appear exactly twice.
//    Find the two elements that appear only once.
    vector<int> singleNumber3(vector<int>& nums) {
        int dif = 0;
        for (int i = 0; i < nums.size(); i++) {
            dif ^= nums[i];
        }
        dif &= -dif;
        vector<int> res = {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & dif) == 0) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        }
        return res;
    }
};