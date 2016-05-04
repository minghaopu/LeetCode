//
//  169_Majority_Element.cpp
//  LeetCode
//
//  Created by roneil on 16/5/4.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for (int index = 0; index < nums.size(); index++) {
            if (count == 0) candidate = nums[index];
            if (candidate == nums[index]) count++;
            else count--;
        }
        return candidate;
        
        // unordered_map<int, int> hash;
        // int ele, num = 0;
        // for (int index = 0; index < nums.size(); index++) {
        //     int t = nums[index];
        //     hash[t] += 1;
        // }
        // for (auto it : hash) {
        //     if (it.second > num) {
        //         ele = it.first;
        //         num = it.second;
        //     }
        // }
        // return ele;
    }
};