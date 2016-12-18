//
//  402.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string removeKdigits(string s, int k) {
        string res = "";
        for (char c : s) {
            while (res.length() && k && res.back() > c) {
                res.pop_back();
                k--;
            }
            if (res != "" || c != '0') res += c;
        }
        while (res != "" && k--) res.pop_back();
        return res == "" ? "0" : res;
    }
};
