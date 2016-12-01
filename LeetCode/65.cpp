//
//  65.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isNumber(string s) {
        int state = 0, flag = 0;
        int start = 0;
        int end = (int)s.length() - 1;
        while (s[start] == ' ') start++;
        while (s[end] == ' ') end--;
        for (int i = start; i <= end; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (state <= 2) state = 2;
                else state = (state <= 5) ? 5 : 7;
                flag = 1;
            } else if (s[i] == '+' || s[i] == '-') {
                if (state == 0 || state == 3) state++;
                else return false;
            } else if (s[i] == '.') {
                if (state <= 2) state = 6;
                else return false;
            } else if (s[i] == 'e') {
                if (flag && (state == 2 || state == 6 || state == 7)) state = 3;
                else return false;
            } else return false;
        }
        return (state == 2 || state == 7 || state == 5 || (flag && state == 6));
    }
};
