//
//  40.cpp
//  LeetCode
//
//  Created by roneil on 11/17/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    set<vector<int>> cache;
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(path, candidates, 0, target);
        return res;
    }
    void dfs(vector<int>& path, vector<int>& candidates, int start, int target) {
        if (target == 0) {
            res.push_back(path);
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (target < candidates[i]) break;
            int rest = target - candidates[i];
            path.push_back(candidates[i]);
            dfs(path, candidates, i + 1, rest);
            path.pop_back();
        }
    }
};
