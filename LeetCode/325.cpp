//
//  325.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0, sum = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) res = i + 1;
            else if (hash.find(sum - k) != hash.end()) res = max(res, i - hash[sum-k]);
            if (hash.find(sum) == hash.end()) hash[sum] = i;
        }
        return res;
    }
};
