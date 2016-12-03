//
//  128.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache(nums.begin(), nums.end());
        int res = 1;
        for (int n : nums) {
            if (cache.find(n) == cache.end()) continue;
            cache.erase(n);
            int pre = n-1, next = n+1;
            while (cache.find(pre) != cache.end()) cache.erase(pre--);
            while (cache.find(next) != cache.end()) cache.erase(next++);
            res = max(res, next - pre - 1); // (next - pre + 1) - 2;
        }
        return res;
    }
};
