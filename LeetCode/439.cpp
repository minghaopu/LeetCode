//
//  439.cpp
//  LeetCode
//
//  Created by neal on 12/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string parseTernary(string s) {
        if (s.length() <= 1) return s;
        int level = 0;
        char c = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '?') level++;
            else if (s[i] == ':') {
                if (--level == 0) return c == 'T' ? parseTernary(s.substr(2, i-2)) : parseTernary(s.substr(i+1));
            }
        }
        return "";
    }
};
