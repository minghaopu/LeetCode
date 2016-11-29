//
//  1. Two Sum.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            if (cache.find(rest) != cache.end()) return {i, cache[rest]};
            cache[nums[i]] = i;
        }
        return {};
    }
};

