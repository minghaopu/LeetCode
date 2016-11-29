//
//  219_Contains_Duplicate.cpp
//  LeetCode
//
//  Created by roneil on 7/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash.insert({nums[i], i});
            }else if (i - hash[nums[i]] > k) {
                hash[nums[i]] = i;
            }else {
                return true;
            }
        }
        return false;
    }
};