//
//  361.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0, row = (int)grid.size(), col = (int)grid[0].size();
        int rm = 0, cc = 0;
        int* cm = new int[col];
        memset(cm, 0, sizeof(cm));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 'W') continue;
                if (j == 0 || grid[i][j-1] == 'W') {
                    rm = countRow(grid, i, j);
                }
                if (i == 0 || grid[i-1][j] == 'W') {
                    cm[j] = countCol(grid, i, j);
                    cc = countCol(grid, i, j);;
                }
                if (grid[i][j] == '0') res = max(rm + cm[j], res);
                // if (grid[i][j] == '0') res = max(rm + cc, res);
            }
        }
        return res;
    }
    int countRow(vector<vector<char>>& grid, int i, int j) {
        int num = 0;
        while (j < grid[0].size() && grid[i][j] != 'W') {
            if (grid[i][j++] == 'E') num++;
        }
        return num;
    }
    int countCol(vector<vector<char>>& grid, int i, int j) {
        int num = 0;
        while (i < grid.size() && grid[i][j] != 'W') {
            if (grid[i++][j] == 'E') num++;
        }
        return num;
    }
};
