//
//  463.cpp
//  LeetCode
//
//  Created by roneil on 11/21/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
int islandPerimeter(vector<vector<int>>& grid) {
    int total = 0;
    int m = int(grid.size());
    if (m == 0) return total;
    int n = int(grid[0].size());
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int cell = 4;
                if (i > 0 &&  grid[i-1][j] == 1) cell--;
                if (j > 0 &&  grid[i][j-1] == 1) cell--;
                if (i < m - 1 &&  grid[i+1][j] == 1) cell--;
                if (j < n - 1 &&  grid[i][j+1] == 1) cell--;
                total += cell;
            }
        }
    }
    return total;
}
