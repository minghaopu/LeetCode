//
//  216.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k * 9 < n || n == 0) return {};
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, k, n, 1);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int> path, int k, int n, int start) {
        if (k == 0) {
            if (n == 0) res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > n) break;
            path.push_back(i);
            dfs(res, path, k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
};
