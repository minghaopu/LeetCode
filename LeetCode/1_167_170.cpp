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
    // 167 two sum - sorted
    vector<int> twoSum_II(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) left++;
            else if (sum > target) right--;
            else return {left+1, right+1};
        }
        return {};
    }
};
// 170. Two Sum III - Data structure design
class TwoSum {
private:
    unordered_map<int, int> cache;
public:
    
    // Add the number to an internal data structure.
    void add(int number) {
        cache[number]++;
    }
    
    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto it = cache.begin(); it != cache.end(); it++) {
            if (it->first * 2 > value) continue;
            int tmp = value - it->first;
            if ((it->first == tmp && it->second > 1) || (it->first != tmp && cache.find(tmp) != cache.end())) return true;
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
