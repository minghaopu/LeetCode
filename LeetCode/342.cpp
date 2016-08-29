//
//  342.cpp
//  LeetCode
//
//  Created by roneil on 8/27/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//
#include "Header.h"


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};
