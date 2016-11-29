//
//  398. Random Pick Index.cpp
//  LeetCode
//
//  Created by roneil on 11/19/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
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
        int start = bounds.first - cache.begin();
        int end = bounds.second - cache.begin();
        int r = end - start;
        return cache[start + (rand() % r)].second;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
