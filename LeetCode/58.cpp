//
//  58.cpp
//  LeetCode
//
//  Created by roneil on 9/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while (s[i] == ' ' && i > -1) {
            i--;
        }
        int j = i;
        while (s[j] != ' ' && j > -1) {
            j--;
        }
        return i - j;
    }
};