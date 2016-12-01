//
//  35.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size();
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
