//
//  233.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        if (n <= 9) return 1;
        int len = (int)to_string(n).length();
        int base = pow(10, len - 1);
        if (n >= 2 * base) return base + (n/base) * countDigitOne(base - 1) + countDigitOne(n%base);
        else return n % base + 1 + countDigitOne(base - 1) + countDigitOne(n%base);
    }
};
