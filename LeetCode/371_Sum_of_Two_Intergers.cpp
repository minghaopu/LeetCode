//
//  371_Sum_of_Two_Intergers.cpp
//  LeetCode
//
//  Created by roneil on 8/23/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        while (b !=  0) {
            c = a & b;
            a ^= b;
            b = c << 1;
        }
        return a;
    }
};