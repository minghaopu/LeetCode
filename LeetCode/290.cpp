//
//  290.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i = 0, j = 0;
        str += ' ';
        unordered_map<char, string> cache;
        unordered_map<string, char> cache2;
        while (i < pattern.size() && j < str.size()) {
            char c = pattern[i++];
            int spaceIndex = (int)str.find(' ', j);
            string word = str.substr(j, spaceIndex - j);
            j = spaceIndex + 1;
            if (cache.find(c) == cache.end() && cache2.find(word) == cache2.end()) {
                cache[c] = word;
                cache2[word] = c;
            } else if (cache[c] != word || cache2[word] != c) return false;
        }
        return i == pattern.size() && j == str.size();
    }
};
