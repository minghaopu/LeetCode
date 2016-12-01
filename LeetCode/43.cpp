//
//  43.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = (int)num1.length();
        int l2 = (int)num2.length();
        string s(l1 + l2, '0');
        for (int i = l1 - 1; i > -1 ; i--) {
            int carry = 0;
            for (int j = l2 - 1; j > -1; j--) {
                int tmp = (num1[i] - '0') * (num2[j] - '0') + (s[i+j+1] - '0') + carry;
                carry = tmp/10;
                s[i+j+1] = char(tmp%10 + '0');
            }
            s[i] += carry;
        }
        int index = 0;
        while (index < l1 + l2 - 1) {
            if (s[index] != '0') break;
            index++;
        }
        return s.substr(index);
    }
};
