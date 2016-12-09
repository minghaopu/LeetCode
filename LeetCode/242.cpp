

//
//  242.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int map[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            map[s[i]-'a']++;
            map[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (map[i] != 0) return false;
        }
        return true;
    }
};
