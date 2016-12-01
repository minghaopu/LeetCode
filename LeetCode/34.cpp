//
//  34.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = (int) nums.size();
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        int left = low;
        low = 0;
        high = (int) nums.size();
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] <= target) low = mid + 1;
            else high = mid;
        }
        int right = low;
        return left == right ? vector<int> {-1, -1} : vector<int> {left, right - 1};
    }
};
