//
//  125_Valid_Palindrome.cpp
//  LeetCode
//
//  Created by roneil on 16/5/13.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            char c1 = s[i];
            if (c1<'0'||(c1>'9'&&c1<'A')||(c1>'Z'&&c1<'a')||c1>'z') {
                i++;
                continue;
            }
            char c2 = s[j];
            if (c2<'0'||(c2>'9'&&c2<'A')||(c2>'Z'&&c2<'a')||c2>'z') {
                j--;
                continue;
            }
            if (toupper(c1) != toupper(c2)) return false;
            i++;
            j--;
            continue;
        }
        return true;
    }
};