

//
//  254.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        return helper(n, 2);
    }
    vector<vector<int>> helper(int n, int start) {
        vector<vector<int>> res;
        for (int i = start; i * i <= n; i++) {
            if (n % i == 0) {
                res.push_back({i, n/i});
                vector<vector<int>> sub = helper(n/i, i);
                for (int j = 0; j < sub.size(); j++) {
                    sub[j].push_back(i);
                    res.push_back(sub[j]);
                }
            }
        }
        return res;
    }
};
