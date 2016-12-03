//
//  135.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = (int) ratings.size();
        if (size < 2) return  size;
        vector<int> tmp(size, 1);
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i-1]) tmp[i] = tmp[i-1] + 1;
        }
        for (int i = size - 1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) tmp[i-1] = max(tmp[i] + 1, tmp[i-1]);
        }
        int sum = 0;
        for (int i = 0; i < size; i++) sum += tmp[i];
        return sum;
    }
};
