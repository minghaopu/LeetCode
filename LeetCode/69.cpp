//
//  69.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1, high = x;
        while (true) {
            int mid = (low + high) / 2;
            if (mid > x/mid) high = mid;
            else {
                if (mid + 1 > x/(mid + 1)) return mid;
                low = mid + 1;
            }
        }
        return 0;
    }
};
