//
//  89.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
// reverse and 'or';
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        int len, half;
        for (int i = 1; i <= n; i++) {
            vector<int> tmp = res;
            reverse(tmp.begin(), tmp.end());
            len = 1 << i;
            res.resize(len);
            half = len / 2;
            for (int j = 0; j < half; j++) {
                res[j+half] = tmp[j] | half;
            }
        }
        return res;
    }
};
