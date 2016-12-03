//
//  97.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = (int)s1.length(), l2 = (int) s2.length(), l3 = (int) s3.length();
        if (l3 != l1 + l2) return false;
        bool table[l1 + 1][l2 + 1];
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                if (i == 0 && j == 0) table[i][j] = true;
                else if (i == 0) table[i][j] = table[i][j-1] && s3[i+j-1] == s2[j-1];
                else if (j == 0) table[i][j] = table[i-1][j] && s3[i+j-1] == s1[i-1];
                else table[i][j] = (table[i-1][j] && s3[i+j-1] == s1[i-1]) || (table[i][j] = table[i][j-1] && s3[i+j-1] == s2[j-1]);
            }
        }
        return table[l1][l2];
    }
};
