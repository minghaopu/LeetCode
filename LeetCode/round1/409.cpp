//
//  409.cpp
//  LeetCode
//
//  Created by roneil on 11/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/*
 *
 *     409. Longest Palindrome
 *
 */
int longestPalindrome(string s) {
    int cache[58];
    memset(cache, 0, sizeof(cache));
    int length = 0;
    int hasOdd = 0;
    for (int i = 0; i < s.length(); i++) {
        cache[s[i]-'A']++;
    }
    for (int i = 0; i < 58; i++) {
        if ((cache[i] & 1) == 0)  {
            length+=cache[i];
        } else {
            hasOdd = 1;
            length+= cache[i] - 1;
        }
    }
    return length + hasOdd;
}
