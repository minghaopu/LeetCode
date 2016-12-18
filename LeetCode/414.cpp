
//
//  414.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty()) return 0;
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        
        for (int n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2 && n < max1) {
                max3 = max2;
                max2 = n;
            } else if (n > max3 && n < max2) {
                max3 = n;
            }
            
        }
        return max3 == LONG_MIN ? (int)max1 : (int)max3;
    }
};
