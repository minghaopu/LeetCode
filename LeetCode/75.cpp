//
//  75.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = {0};
        for (int n : nums) color[n]++;
        int i = 0, j = 0;
        while (j < 3) {
            while (color[j]-->0) nums[i++] = j;
            j++;
        }
    }
};
