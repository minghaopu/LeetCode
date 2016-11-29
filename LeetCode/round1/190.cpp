//
//  190.cpp
//  LeetCode
//
//  Created by roneil on 8/27/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {                          //abcdefgh
        n = (n >> 16) | (n << 16);                              //efghabcd
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);  //ghefcdab
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);  //hgfedcba
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};