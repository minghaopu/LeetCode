//
//  365. Water and Jug Problem.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include <stdio.h>
/* 
 * Euclidean algorithm 辗转相除法
 */
class Solution {
private:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == z || y == z || x + y == z || z == 0) return true;
        if (z > x + y || x == 0 || y == 0 || z % gcd(x, y) != 0) return false;
        return true;
    }
};
