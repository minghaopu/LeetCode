//
//  293_294.cpp
//  LeetCode
//
//  Created by neal on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        if (s.length() < 2) return {};
        vector<string> res;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1] && s[i] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                res.push_back(s);
                s[i+1] = '+';
                s[i] = '+';
            }
        }
        return res;
    }
    bool canWin(string s) {
        if (s == "") return false;
        return helper(s);
    }
    bool helper(string s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1] && s[i] == '+') {
                string t = s;
                t[i] = '-';
                t[i+1] = '-';
                if (!helper(t)) return true;
            }
        }
        return false;
    }
};
