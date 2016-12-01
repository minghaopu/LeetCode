//
//  58.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = (int)s.length()-1;
        while (s[i] == ' ' && i > -1) i--;
        int j = i;
        while (s[i] != ' ' && i > -1) i--;
        return j - i;
    }
};
