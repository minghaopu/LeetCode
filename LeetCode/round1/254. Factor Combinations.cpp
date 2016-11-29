//
//  254. Factor Combinations.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    
    vector<int> nums;
    vector<vector<int>> res;
public:
    vector<vector<int>> getFactors(int n) {
        return getSubFactors(n, 2);
    }
    vector<vector<int>> getSubFactors(int n, int k) {
        if (n <= 0 || k <= 0) return {};
        vector<vector<int>> res;
        for (int i = k; i <= sqrt(n); i++) {
            if (n % i == 0) {
                res.push_back({i, n/i});
                vector<vector<int>> sub = getSubFactors(n/i, i);
                for (int j = 0; j < sub.size(); j++) {
                    vector<int> tmp = sub[j];
                    tmp.push_back(i);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
