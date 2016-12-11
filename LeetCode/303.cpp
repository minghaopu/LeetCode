
//
//  303.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class NumArray {
    int *sums;
public:
    NumArray(vector<int> &nums) {
        int l = (int) nums.size();
        sums = new int[l + 1];
        sums[0] = 0;
        for (int i = 1; i <= l; i++) {
            sums[i] = sums[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
