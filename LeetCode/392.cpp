//
//  392.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) return false;
        if (s == t) return true;
        int i = 0, j = 0;
        while (j < t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.length();
    }
};
