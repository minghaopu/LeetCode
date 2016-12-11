//
//  278.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        while (left < right) {
            mid = left + (right - left) / 2; //prevent left + right overflow
            if (!isBadVersion(mid)) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
