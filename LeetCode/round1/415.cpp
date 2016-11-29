//
//  415.cpp
//  LeetCode
//
//  Created by roneil on 11/17/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
string addStrings(string num1, string num2) {
    if (num1.length() < num2.length()) return addStrings(num2, num1);
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    string res = "";
    while (j > -1) {
        int tmp = (num1[i--] - '0') + (num2[j--] - '0') + carry;
        if (tmp >= 10) {
            carry = 1;
            tmp -= 10;
        } else {
            carry = 0;
        }
        res = char(tmp + '0') + res;
        
    }
    while (i > -1) {
        int tmp = (num1[i--] - '0') + carry;
        if (tmp >= 10) {
            carry = 1;
            tmp -= 10;
        } else {
            carry = 0;
        }
        res = char('0' + tmp) + res;
    }
    if (carry != 0) res = char('0' + carry) + res;
    return res;
}
