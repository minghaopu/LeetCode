//
//  347.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = (int) nums.size();
        if (k > len) return nums;
        unordered_map<int, int> cache;
        for (int n : nums) cache[n]++;
        vector<vector<int>> buckets(len + 1);
        for (auto p : cache) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> res;
        for (int i = len, j = 0; i > -1 && j <= k; i--) {
            for (int n : buckets[i]) {
                res.push_back(n);
                j++;
                if (j == k) return res;
            }
        }
        return res;
    }
};
