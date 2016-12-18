//
//  396.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        int n = (int) A.size();
        int sum = 0, res = INT_MIN;
        int pre = 0, cur = 0;
        for (int a : A) sum += a;
        for (int i = 0; i < n; i++) cur += i * A[i];
        res = cur;
        for (int i = 1; i < n; i++) {
            pre = cur;
            cur = pre + sum - n * A[n-i];
            res = max(cur, res);
        }
        return res;
    }
};
