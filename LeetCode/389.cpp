//
//  389.cpp
//  LeetCode
//
//  Created by roneil on 9/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    /*
     *  using sum; 6ms
     */
    char findTheDifference_sum(string s, string t) {
        int tmp = 0;
        for (int i = 0; i < t.length(); i++) {
            tmp += t[i];
        }
        for (int i = 0; i < s.length(); i++) {
            tmp -= s[i];
        }
        return (char)tmp;
    }
    /*
     *  using sum; 3ms
     */
    char findTheDifference_XOR(string s, string t) {
        int tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp ^= t[i] ^ s[i];
        }
        return (char)(tmp ^ t[t.length() - 1]);
    }
};
