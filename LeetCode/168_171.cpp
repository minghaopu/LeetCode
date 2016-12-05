//
//  168_171.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string convertToTitle(int n) {
        char map[26] = {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
        string res;
        while (n > 0) {
            res = map[n%26] + res;
            n = (n-1)/26;
        }
        return  res;
    }
    int titleToNumber(string s) {
        int num = 0;
        for (char c : s) num = num * 26 + (c - 'A' + 1);
        return num;
    }
};
