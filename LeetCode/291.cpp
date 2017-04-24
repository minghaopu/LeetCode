//
//  291.cpp
//  LeetCode
//
//  Created by neal on 4/22/17.
//  Copyright © 2017 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_map<string, char> tokenMap;
    unordered_map<char, string> chMap;
public:
    bool wordPatternMatch(string pattern, string str) {
        return helper(str, pattern, 0, 0);
    }
    bool helper(string& str, string& pattern, int i, int j) {
        if (i == pattern.length() && j == str.length()) return true;
        else if (i == pattern.length() || j == str.length()) return false;
        else if (str.length() - j >= pattern.length() - i) {
            char ch = pattern[i];
            for (int len = 1; len <= str.length() - j - (pattern.length() - i - 1); len++) {
                string token = str.substr(j, len);
                if (tokenMap.find(token) == tokenMap.end() && chMap.find(ch) == chMap.end()) {
                    chMap[ch] = token;
                    tokenMap[token] = ch;
                    if (helper(str, pattern, i+1, j + len)) return true;
                    tokenMap.erase(token);
                    chMap.erase(ch);
                } else if (tokenMap.find(token) != tokenMap.end() && tokenMap[token] != ch) continue;
                else if (chMap.find(ch) != chMap.end() && chMap[ch] != token) continue;
                else if (helper(str, pattern, i+1, j + len)) return true;
            }
            return false;
        }
        else return false;
    }
};
