//
//  310.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> graph(n);
        for (auto e : edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        vector<int> degree(n, 0);
        int remain = n;
        for (int i = 0; i < n; i++) degree[i] = (int) graph[i].size();
        while (remain > 2) {
            vector<int> toDelete;
            for (int i = 0; i < n; i++) {
                if (degree[i] == 1) {
                    remain--;
                    degree[i] = -1;
                    toDelete.push_back(i);
                }
            }
            for (int node : toDelete) {
                for (int neighbor : graph[node]) degree[neighbor]--;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (degree[i] >= 0) res.push_back(i);
        }
        return res;
    }
};
