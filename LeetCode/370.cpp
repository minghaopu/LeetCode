//
//  370.cpp
//  LeetCode
//
//  Created by neal on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for (int i = 0; i < updates.size(); i++) {
            int start = updates[i][0];
            int end = updates[i][1];
            int val = updates[i][2];
            res[start] += val;
            if (end != length - 1) res[end + 1] -= val;
        }
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += res[i];
            res[i] = sum;
        }
        return res;
    }
};
