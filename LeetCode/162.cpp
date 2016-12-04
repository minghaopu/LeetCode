//
//  162.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = (int)nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if (nums[mid] > nums[mid+1]) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
