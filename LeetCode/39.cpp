//
//  39.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, candidates, target, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            dfs(res, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
