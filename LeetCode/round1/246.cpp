//
//  246.cpp
//  LeetCode
//
//  Created by roneil on 9/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isStrobogrammatic(string num) {
        stack<char> s;
        int i;
        for (i = 0; i < num.length()/2; i++) {
            char tmp = num[i];
            if (tmp == '2' ||tmp == '3' || tmp == '4' || tmp == '5' || tmp == '7' ) return false;
            s.push(num[i]);
        }
        if (num.length() % 2 == 1) {
            char tmp = num[i];
            if (tmp == '2' ||tmp == '3' || tmp == '4' || tmp == '5' || tmp == '7' ) return false;
            i++;
        }
        while (i < num.length()) {
            char top = s.top();
            char tmp = num[i];
            if (tmp == '2' ||tmp == '3' || tmp == '4' || tmp == '5' || tmp == '7' ) return false;
            if ((top == '1' && tmp == '1') || (top == '0' && tmp == '0') || (top == '8' && tmp == '8') || (top == '9' && tmp == '6') || (top == '6' && tmp == '9')) {
                s.pop();
            }
            i++;
        }
        return s.size() == 0;
    }
};
