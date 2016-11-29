//
//  5. Longest Palindromic Substring.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string longestPalindrome(string s) {
        int l = int(s.length());
        int length = 1;
        int start = 0;
        int table[1000][1000] = {0};
        for (int i = 0; i < l; i++) table[i][i] = 1;
        for (int i = 0; i < l - 1; i++) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = 1;
                length = 2;
                start = i;
            }
        }
        
        for (int len = 3; len <= l; len++) {
            for (int i = 0; i < l - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = 1;
                    length = len;
                    start = i;
                }
            }
        }
        return s.substr(start, length);
    }
};
