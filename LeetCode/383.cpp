//
//  383.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {0};
        for (char c : magazine) map[c-'a']++;
        for (char c : ransomNote) {
            if (--map[c-'a'] < 0) return false;
        }
        return true;
    }
};
