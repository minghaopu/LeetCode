//
//  29.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/30.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int res = 0;
        int sign = (dividend < 0) ^ (divisor < 0); // 0 -> result is positive; 1 -> result is negative;
        long dd = abs((long)dividend);
        long dv = abs((long)divisor);
        while (dd >= dv) {
            long tmpDiv = dv;
            int tmp = 1;
            while (dd > (tmpDiv << 1)) {
                tmpDiv <<= 1;
                tmp <<= 1;
            }
            dd -= tmpDiv;
            res += tmp;
        }
        return sign == 0 ? res : -res;
    }
};
