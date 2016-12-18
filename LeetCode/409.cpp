//
//  409.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int longestPalindrome(string s) {
        int map[128] = {0};
        for (char c : s) map[c]++;
        int len = 0, odd = 0;
        for (int i = 0; i < 128; i++) {
            if (map[i] != 0) {
                if (map[i] & 1) odd++;
                len += map[i];
            }
        }
        return odd == 0 ? len : len - odd + 1;
    }
};
