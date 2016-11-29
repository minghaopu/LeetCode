//
//  372_Super_Pow.cpp
//  LeetCode
//
//  Created by roneil on 11/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    const int base = 1337;
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last) % base;
    }
    int powmod(int a, int k) {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; i++) {
            result = (result * a) % base;
        }
        return result;
    }
};
