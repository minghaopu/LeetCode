//
//  365.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == z || y == z || x + y == z || z == 0) return true;
        if (z > x + y || x == 0 || y == 0 || z % gcd(x, y) != 0) return false;
        return true;
    }
};
