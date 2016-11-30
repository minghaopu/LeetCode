//
//  8. String to Integer (atoi).cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int myAtoi(string str) {
        if (str == "") return 0;
        long num = 0;
        int sign = 1;
        int start = 0, end = (int)str.length() - 1;
        while (str[start] == ' ') start++;
        while (str[end] == ' ') end--;
        for (int i = start; i <= end; i++) {
            if (isdigit(str[i])) {
                if (num < INT_MAX && (num * 10 + str[i] - '0' < INT_MAX)) num = num * 10 + str[i] - '0';
                else if (sign == -1 && num * 10 + str[i] - '0' == INT_MAX) num = num * 10 + str[i] - '0';
                else return sign == 1 ? INT_MAX : INT_MIN;
            } else {
                if (i == start && (str[i] == '+' || str[i] == '-')) {
                    sign = str[i] == '+' ? 1 : -1;
                } else return sign * (int)num;
            }
        }
        return (int)num * sign;
    }
};
