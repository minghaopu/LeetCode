//
//  7. Reverse Integer.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        long tmp = x;
        tmp *= sign;
        long num = 0;
        while (tmp) {
            int mod = tmp % 10;
            tmp /= 10;
            num = num * 10 + mod;
        }
        if (num > INT_MAX) return 0;
        return int(sign * num);
    }
};
