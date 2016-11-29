//
//  441. Arranging Coins.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include <math.h>
class Solution {
public:
    int arrangeCoins(int n) {
        // 1 + 2 +3 + ....x <= n;
        // (x+1) * x / 2 <= n;
        // x^2 + x <= 2n;
        // x^2 + x + 1/4 <= 2n + 1/4;
        // (x+1/2) ^ 2 <= 2n + 1/4;
        // x + 1/2 <= sqrt(2n + 1/4);
        // x <= sqrt(2n + 1/4) - 1/2;
        return floor(sqrt(2* double(n) + 0.25) - 0.5);
    }
};
