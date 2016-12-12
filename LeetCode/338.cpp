
//
//  338.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        int base = 0;
        for (int i = 1; i <= num; i++) {
            if ((i & (i-1)) == 0) {
                res[i] = 1;
                base = i;
            } else {
                res[i] = res[base] + res[i - base];
            }
        }
        return res;
    }
    vector<int> countBits_method2(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) res[i] = res[i & (i - 1)] + 1;
        return res;
    }
};
