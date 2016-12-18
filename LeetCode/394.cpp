//
//  394.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
    string helper(string s, int& index) {
        int num = 0;
        string res = "";
        while (index < s.length() && s[index] != ']') {
            if (isalpha(s[index])) {
                res += s[index++];
            } else {
                while (isdigit(s[index])) num = num * 10 + s[index++] - '0';
                index++; // skip [;
                string temp = helper(s, index);
                index++; // to next char;
                while (num--) res += temp;
                num = 0;
            }
        }
        return res;
    }
};
