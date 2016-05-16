//
//  242_Valid_Anagram.cpp
//  LeetCode
//
//  Created by roneil on 16/5/15.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> hash;
        for (char &c:s) {
            hash[c]++;
        }
        for (char &c:t) {
            hash[c]--;
        }
        for (auto it:hash) {
            if (it.second != 0) return false;
        }
        return true;
    }
};