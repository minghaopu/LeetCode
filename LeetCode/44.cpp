//
//  44.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = (int)s.length(), pl = (int)p.length(), jstar = -1, istar = -1, i, j;
        for (i = 0, j = 0; i < sl; i++, j++) {
            if (p[j] == '*') {
                istar = i;
                jstar = j;
                i--; // avoid i++;
            } else {
                if (s[i] != p[j] && p[j] != '?') {
                    if (jstar >= 0) {
                        i = istar;
                        istar++;
                        j = jstar;
                    } else return false;
                }
            }
        }
        while (p[j] == '*') j++;
        return j == pl;
    }
};
