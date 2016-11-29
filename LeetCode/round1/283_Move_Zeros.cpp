//
//  283_Move_Zeros.cpp
//  LeetCode
//
//  Created by roneil on 16/4/20.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& n) {
        nums = n;
    }
    void moveZeros() {
        int i = -1; // non-zero position
        int j = 0;  // zero postion
        int length = (int)nums.size();
        int temp;
        while (j<length) {
            if (nums[j] == 0) {
                j++;
                continue;
            }
            i++;
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
    
};

