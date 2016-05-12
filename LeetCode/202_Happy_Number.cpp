//
//  202_Happy_Number.cpp
//  LeetCode
//
//  Created by roneil on 16/5/11.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> hash;
        int sum, last;
        while (n > 9) {
            if (hash.find(n) != hash.end()) return false;
            hash.insert({n, true});
            sum = 0;
            while (n > 0) {
                last = n%10;
                sum += last * last;
                n /= 10;
            }
            n = sum;
        }
        return n == 1 || n == 7;
    }
};