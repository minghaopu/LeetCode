//
//  87.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        int count[128] = {0}, len = (int)s1.length();
        for (int i = 0; i < len; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (int i = 0; i < len; i++) {
            if(count[s1[i]] != 0) return false;
        }
        for (int i = 1; i < len; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            else if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) return true;
        }
        return false;
    }
};
