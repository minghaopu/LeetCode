//
//  20.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') S.push(c);
            else {
                if (S.empty()) return false;
                char t = S.top();
                if ((t == '(' && c == ')') || (t == '[' && c == ']') || (t == '{' && c == '}')) S.pop();
                else return false;
            }
        }
        return S.empty();
    }
};
