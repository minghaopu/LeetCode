//
//  50_Pow(x, n).cpp
//  LeetCode
//
//  Created by roneil on 16/4/28.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return abs(x) == 1.0?1.00000:0.00000;
        else if (n < 0) return 1.0/pows(x, -n);
        else return pows(x, n);
    }
    double pows(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        double sub = pows(x, n/2);
        return sub * sub * pows(x, n%2);
    }
};
