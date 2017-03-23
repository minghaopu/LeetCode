//
//  217_219_220.cpp
//  LeetCode
//
//  Created by roneil on 12/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() < nums.size();
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = (int) nums.size();
        if (n < 2 || k <= 0) return false;
        if (k > n) k = n - 1;
        unordered_set<int> cache;
        for (int i = 0; i < n; i++) {
            if (i > k) cache.erase(nums[i - k - 1]);
            if (cache.count(nums[i])) return true;
            cache.insert(nums[i]);
        }
        return false;
    }
};
