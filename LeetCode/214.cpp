//
//  214.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        string l = s + "#" + rs;
        vector<int> p(l.length(), 0);
        for (int i = 1; i < l.length(); i++) {
            int j = p[i-1];
            while (j > 0 && l[i] != l[j]) j = p[j-1];
            
            p[i] = j + 1;
        }
        return rs.substr(0, s.length() - p[l.length() - 1]) + s;
    }
};
