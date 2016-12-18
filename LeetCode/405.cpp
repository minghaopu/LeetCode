//
//  405.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        int count = 0;
        string s = "";
        while (num != 0 && count < 8) {
            int mod = num & 15;
            if (mod < 10) s += '0' + mod;
            else s += 'a' + mod - 10;
            num >>= 4;
            count++;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
