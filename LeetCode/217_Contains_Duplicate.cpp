//
//  217_Contains_Duplicate.cpp
//  LeetCode
//
//  Created by roneil on 16/5/9.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int l = nums.size();
        if (l < 2) return false;
        unordered_map<int,int> hash;
        for (int i = 0; i < l; i++) {
            if (hash.find(nums[i]) != hash.end()) return true;
            hash.insert({nums[i], 1});
        }
        return false;
    }
};