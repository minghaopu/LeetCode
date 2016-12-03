//
//  136_137_260.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = 0;
        for (int n : nums) tmp ^= n;
        return tmp;
    }
    int singleNumber_II(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int n : nums) {
            two |= (one & n); // if A appear even times, than (A in ones) & A = A, then twos = A;
            one ^= n; // if A appear odd times, than one contain A, else ones do not contain A;
            three = one & two; // if A appear three times, twos contain A, ones contain A, therefore three contain A;
            one ^= three;// empty one; since one contain A, three contain A, one ^ three = 0;
            two ^= three; // empty two;
        }
        return one;
    }
    vector<int> singleNumber_III(vector<int>& nums) {
        vector<int> res {0,0};
        int difBit = 0;
        for (int n : nums) difBit ^= n;
        difBit &= -difBit; // get the lowest different bit of the two number; A & -A = the lowest bit of this number;
        for (int n : nums) {
            if (n & difBit) res[0] ^= n; // get all the number whose lowest different bit is 1;
            else res[1] ^= n; // get all the number whose lowest different bit is 0;
        }
        return res;
    }
};
