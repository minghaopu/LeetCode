//
//  334.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int n : nums) {
            if (n <= min1) {
                min1 = n;
            } else if (n <= min2) {
                min2 = n;
            } else return true;
        }
        return false;
    }
};
