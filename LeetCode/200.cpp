//
//  200.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    sum++;
                    dfs(grid, i, j);
                }
            }
        }
        return sum;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0' || grid[i][j] == '2') return;
        grid[i][j] = '2';
        if (i > 0) dfs(grid, i-1, j);
        if (j > 0) dfs(grid, i, j-1);
        if (i < grid.size() - 1) dfs(grid, i+1, j);
        if (j < grid[0].size() - 1) dfs(grid, i, j+1);
    }
};
