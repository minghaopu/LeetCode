
//
//  306.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) return false;
        return helper(num, 0, 1, 1);
    }
    bool helper(string num, int start, int num1Len, int num2Len) {
        long num1, num2, num3;
        string rest, sub3;
        for (int l1 = num1Len; start + l1 <= num.size() - 2; l1++) {
            if (num[start] == '0' && l1 > 1) break;
            for (int l2 = num2Len; start + l1 + l2 <= num.size() - 1; l2++) {
                if (num[start + l1] == '0' && l2 > 1) break;
                num1 = stol(num.substr(start, l1));
                num2 = stol(num.substr(start + l1, l2));
                num3 = num1 + num2;
                sub3 = to_string(num3);
                rest = num.substr(start + l1 + l2);
                if (rest == sub3) return true;
                if (rest.find(sub3) == 0) {
                    if (helper(num, start + l1, l2, (int)sub3.size())) return true;
                }
            }
        }
        return false;
    }
};
