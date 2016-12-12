//
//  349_350.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) return {};
        vector<int> res;
        unordered_set<int> cache;
        for (int n : nums1) cache.insert(n);
        for (int n : nums2) {
            if (cache.find(n) != cache.end()) {
                res.push_back(n);
                cache.erase(n);
            }
        }
        return res;
    }
    vector<int> intersect_II(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int n : nums1) hash[n]++;
        for (int n : nums2) {
            if (hash[n] != 0) {
                res.push_back(n);
                hash[n]--;
            }
        }
        return res;
    }
};
