//
//  400.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int findNthDigit_TLE(int n) {
        int i = 1;
        int count = 0;
        while (count < n) {
            count += log10(i) + 1;
            i++;
        }
        string s = to_string(i-1);
        int shift = count - n;
        return s[s.length() - 1 - shift] - '0';
        
    }
    int findNthDigit(int n) {
        long base = 9;
        int bit = 1;
        int num = 0;
        while (n > base * bit) {
            n -= base * bit;
            num += base;
            base *= 10;
            bit++;
        }
        int shift = (n-1) % bit;
        
        num += (n-1)/bit + 1;
        string s = to_string(num);
        return s[shift] - '0';
    }
};
