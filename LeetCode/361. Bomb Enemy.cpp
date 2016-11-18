//
//  361. Bomb Enemy.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].size() == 0) return 0;
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();
        int rm = 0;
        int* cm = new int[col];
        memset(cm, 0, sizeof(cm));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 'W') continue;
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rm = countRow(grid, i, j);
                }
                if (i == 0 || grid[i-1][j] == 'W') {
                    cm[j] = countCol(grid, i, j);
                }
                if (grid[i][j] == '0') result = max(rm + cm[j], result);
            }
        }
        return result;
    }
    int countRow(vector<vector<char>>& grid, int i, int j) {
        int num = 0;
        while (j < grid[0].size() && grid[i][j] != 'W') {
            if (grid[i][j] == 'E') num++;
            j++;
        }
        return num;
    }
    int countCol(vector<vector<char>>& grid, int i, int j) {
        int num = 0;
        while (i < grid.size() && grid[i][j] != 'W') {
            if (grid[i][j] == 'E') num++;
            i++;
        }
        return num;
    }
};
