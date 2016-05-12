//
//  28_Implement_strStr.cpp
//  LeetCode
//
//  Created by roneil on 16/5/12.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int m = haystack.length(), n = needle.length();
        if (n == 0) return 0;
        while (i < m && j < n) {
            if (m-i < n-j) return -1;
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }else if (j == 0) {
                i++;
            }else{
                i = i-j+1;
                j = 0;
                
            }
        }
        return j == n?i-n:-1;
    }
};