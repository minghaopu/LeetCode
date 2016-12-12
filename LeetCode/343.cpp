

//
//  343.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n % 3 == 0) return pow(3, n/3);
        else if (n % 3 == 1) return 4 * pow(3, (n-4) / 3);
        else return 2 * pow(3, (n-2) / 3);
    }
};
