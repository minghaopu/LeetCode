//
//  191.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            m <<= 1;
            m |= n & 1;
        }
        return m;
    }
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n & 1) count++;
            n >>= 1;
        }
        return count;
    }
};
