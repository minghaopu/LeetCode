//
//  28.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/30.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
// Knuth–Morris–Pratt(KMP) Pattern Matching(Substring search)
// https://www.youtube.com/watch?v=GTJr8OvyEVQ
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;
        
        int m = (int)haystack.length(), n = (int)needle.length();
        int *next = new int[n];
        memset(next, 0, sizeof(int) * n);
        // create next array to record prefix position
        int i = 1, j = 0;
        while (i < n) {
            if (needle[i] != needle[j]) {
                if (j > 0) j = next[j-1];
                else i++;
            } else {
                next[i] = j + 1;
                i++;
                j++;
            }
        }
        i = 0;
        j = 0;
        
        // match
        while (i < m) {
            if (haystack[i] == needle[j]) {
                if (j == n - 1) return i - (n - 1);
                else {
                    i++;
                    j++;
                }
            } else {
                if (j == 0) i++;
                else j = next[j-1];
            }
        }
        delete[] next;
        return -1;
    }
};
