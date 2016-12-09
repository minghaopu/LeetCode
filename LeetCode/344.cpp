//
//  344.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = (int) s.length()-1;
        while (i < j) swap(s[i++], s[j--]);
        return s;
    }
};
