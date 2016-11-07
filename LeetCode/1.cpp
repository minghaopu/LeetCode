//
//  1.cpp
//  LeetCode
//
//  Created by roneil on 11/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            if (hash.find(rest) != hash.end()) {
                res[0] = i;
                res[1] = hash[rest];
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};