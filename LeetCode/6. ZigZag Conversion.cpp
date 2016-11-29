//
//  6. ZigZag Conversion.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() < 2) return s;
        vector<string> rows(numRows, "");
        int cycle = 2 * numRows - 2;
        for (int i = 0; i < s.length(); i++) {
            if ((i%cycle) < numRows) {
                rows[(i%cycle)] += s[i];
            } else {
                rows[cycle - (i%cycle)] += s[i];
            }
        }
        string res = "";
        for (int i = 0; i < numRows; i++) {
            res += rows[i];
        }
        return res;
    }
};
