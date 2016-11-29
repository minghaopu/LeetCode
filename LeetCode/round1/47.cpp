//
//  47.cpp
//  LeetCode
//
//  Created by roneil on 11/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/*
 *
 *    47. Permutations II
 *
 */
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        recursive(0, int(nums.size()) - 1, nums);
        return result;
    }
    void recursive(int start, int end, vector<int> nums) {
        if (start == end) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i <= end; i++) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            recursive(start + 1, end, nums);
        }
    }
};
