//
//  191_Number_of_1_Bits.cpp
//  LeetCode
//
//  Created by roneil on 16/5/2.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        for (int i = 31; i > -1; i--) {
            uint32_t mod = pow(2, i);
            if (n<mod) continue;
            num++;
            n = n%mod;
        }
        return num;
    }
    int hammingWeight1(uint32_t n) {
        int num = 0;
        for(int i=0;i<32;i++){
            num += n&1;
            n = n>>1;
        }
        return num;
    }
};