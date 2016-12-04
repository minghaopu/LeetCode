//
//  161.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s == t) return false;
        int lenDif = int (s.length() - t.length());
        if (abs(lenDif) > 1) return false;
        if (s == "" || t == "") return true;
        if (lenDif == -1) return isOneEditDistance(t, s);
        int i = 0, j = 0;
        while (s[i] == t[j] && i < s.length() && j < t.length()) {
            i++;
            j++;
        }
        if (lenDif == 1) {
            if (i == s.length()-1) return true;
            else {
                i++;
                while (s[i] == t[j] && i < s.length() && j < t.length() ) {
                    i++;
                    j++;
                }
                if (i == s.length()) return true;
            }
        } else {
            if (i == s.length()) return true;
            else {
                i++;
                j++;
                while (s[i] == t[j] && i < s.length() && j < t.length() ) {
                    i++;
                    j++;
                }
                if (i == s.length()) return true;
            }
        }
        return false;
    }
};
