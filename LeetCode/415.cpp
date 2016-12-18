//
//  415.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "") return num2;
        if (num2 == "") return num1;
        if (num1.length() < num2.length()) return addStrings(num2, num1);
        num1 = '0' + num1;
        int carry = 0, l1 = (int) num1.length() - 1, l2 = (int) num2.length() - 1;
        while (l2 > -1) {
            carry += num1[l1] - '0' + num2[l2] - '0';
            num1[l1] = '0' + carry % 10;
            carry /= 10;
            l1--;
            l2--;
        }
        while (carry) {
            carry += num1[l1] - '0';
            num1[l1] = '0' + carry % 10;
            carry /= 10;
            l1--;
        }
        return num1[0] == '0' ? num1.substr(1) : num1;
    }
};
