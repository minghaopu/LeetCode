//
//  50.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return abs(x) == 1.0? 1.0 : 0.0;
        else if (n < 0) return 1.0/recursivePow(x, -n);
        else return recursivePow(x, n);
    }
    double recursivePow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double sub = recursivePow(x, n/2);
        return sub * sub * recursivePow(x, n % 2);
    }
};
