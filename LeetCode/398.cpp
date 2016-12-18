//
//  398.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class SolutionI {
private:
    int *cache;
    map<int, int> counts;
public:
    SolutionI(vector<int> nums) {
        int size = (int) nums.size();
        cache = new int[size];
        memset(cache, 0, sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            cache[i] = nums[i];
        }
        for (int n : nums) {
            counts[n]++;
        }
    }
    
    int pick(int target) {
        int count = (rand() % counts[target]) + 1;
        int index = 0;
        while (count) {
            if (cache[index++] == target) count--;
        }
        return index-1;
    }
};
class Solution {
private:
    typedef pair<int, int> pp;
    static bool comp(const pp& a, const pp& b) { return a.first < b.first;};
    vector<pp> cache;
public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cache.push_back({nums[i], i});
        }
        sort(cache.begin(), cache.end(), comp);
    }
    
    int pick(int target) {
        auto bounds = equal_range(cache.begin(), cache.end(), pp(target, 0), comp);
        int start = int(bounds.first - cache.begin());
        int end = int(bounds.second - cache.begin());
        int r = end - start;
        return cache[start + (rand() % r)].second;
        
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
