//
//  459.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution_II {
public:
    bool repeatedSequencePattern(string str) {
        if (str.length() < 2) return false;
        int map[26] = {0};
        int count = 0;
        for (char c : str) {
            if(map[c-'a']++ == 0) count++;
        }
        if (count == 1) return true;
        int g = -1;
        for (int i = 0; i < 25; i++) {
            if (map[i] > 0) g = gcd(g, map[i]);
        }
        return g != 1;
    }
    int gcd(int a, int b) {
        if (a == -1) return b;
        return b == 0 ? a : gcd(b, a % b);
    }
    bool repeatedSubstringPattern(string str) {
        int l = (int) str.length();
        if (l < 2) return false;
        for (int sublen = l / 2; sublen >= 1; sublen--) {
            if (l % sublen == 0) {
                int count = l / sublen;
                string sub = str.substr(0, sublen);
                string tmp = "";
                while (count--) tmp += sub;
                if (tmp == str) return true;
            }
        }
        return false;
    }
};
