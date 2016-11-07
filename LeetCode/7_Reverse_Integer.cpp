//
//  7_Reverse_Integer.cpp
//  LeetCode
//
//  Created by roneil on 11/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"


class Solution {
public:
    int reverseInteger(int X) {
        long res = 0;
        while (X != 0) {
            res = res * 10 + X % 10;
            X /= 10;
        }
        if (abs(X) > INT_MAX) return 0;
        return (int)res;
    }
};