//
//  383.cpp
//  LeetCode
//
//  Created by roneil on 9/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool canConstruct_map(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (int i = 0; i < ransomNote.length(); i++) {
            m[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            m[magazine[i]]--;
        }
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second > 0) return false;
        }
        return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {0};
        for (int i = 0; i < ransomNote.length(); i++) {
            m[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            m[magazine[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (m[i] > 0) return false;
        }
        return true;
    }
};
