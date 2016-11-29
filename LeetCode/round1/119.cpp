//
//  119.cpp
//  LeetCode
//
//  Created by roneil on 9/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex + 1, 0);
        r[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                r[j] += r[j-1];
            }
        }
        return r;
    }
};