//
//  367.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        long mid, val;
        while (left <= right) {
            mid = left + (right - left) / 2;
            val = mid * mid;
            if (val == num) return true;
            else if (val < num) left = mid + 1;
            else right = mid - 1;
            
        }
        return false;
    }
};
