//
//  224_227.cpp
//  LeetCode
//
//  Created by roneil on 12/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, num = 0;
        stack<int> nums, ops;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '+') {
                res += num * sign;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += num * sign;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                nums.push(res);
                res = 0;
                ops.push(sign);
                sign = 1;
            } else if (c == ')') {
                res += num * sign;
                num = 0;
                sign = 1;
                res = res * ops.top() + nums.top();
                ops.pop();
                nums.pop();
            }
        }
        res += num * sign;
        return res;
    }
    int calculate_II(string s) {
        int res = 0, num = 0, internal = 0, i = 0;
        char op = '+';
        while (i < s.length()) {
            if (isdigit(s[i])) {
                num = 0;
                while (i < s.length() && isdigit(s[i])) num = num * 10 + s[i++] - '0';
                if (op == '+' || op == '-') {
                    res += internal;
                    internal = num * (op == '+' ? 1 : -1);
                } else if (op == '*') internal *= num;
                else internal /= num;
            } else if (s[i] != ' ') op = s[i++];
            else i++;
        }
        return res + internal;
    }
};
