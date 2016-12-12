//
//  371.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while (b) {
            sum = (a ^ b);
            b = (a & b) << 1;
            a = sum;
        }
        return sum;
    }
};
