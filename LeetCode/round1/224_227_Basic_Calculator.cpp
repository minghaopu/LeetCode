//
//  224_227_Basic_Calculator.cpp
//  LeetCode
//
//  Created by roneil on 11/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        int num = 0;
        stack<int> nums;
        stack<int> ops;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += num * sign;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += num * sign;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                nums.push(result);
                ops.push(sign);
                sign = 1;
                result = 0;
            } else if (c == ')') {
                result += num*sign;
                num = 0;
                result = result * ops.top() + nums.top();
                ops.pop();
                nums.pop();
            }
        }
        result += num * sign;
        return result;
    }
    int calculate2(string s) {
        int internal = 0;
        int num = 0;
        int result = 0;
        char op = '+';
        int i = 0;
        while (i < s.length()) {
            
            if (isdigit(s[i])) {
                num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if (op == '+' || op == '-') {
                    result += internal;
                    internal = num * (op == '+' ? 1:-1);
                } else if (op == '*') {
                    internal *= num;
                } else {
                    internal /= num;
                }
            } else {
                
                if (s[i] != ' ') op = s[i];;
                i++;
                
            }
        }
        return result += internal;
    }
};
