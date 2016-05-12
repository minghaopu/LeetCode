//
//  177_Excel_Sheet_Column_Number.cpp
//  LeetCode
//
//  Created by roneil on 16/5/12.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int l = s.length() - 1;
        for (int i = l; i >= 0; i--) {
            sum += (int(s[i])-64)*pow(26,l-i);
        }
        return sum;
    }
};