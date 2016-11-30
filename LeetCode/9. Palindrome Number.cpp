//
//  9. Palindrome Number.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int base = 1;
        while (x/10 >= base) base *= 10;
        while (x > 0) {
            if (x % 10 != x / base) return false;
            x = (x %= base) / 10;
            base /= 100;
            
        }
        return true;
    }
};
