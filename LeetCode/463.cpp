//
//  463.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int total = 0, m = (int) grid.size(), n = (int) grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int cell = 4;
                    if (i > 0 && grid[i-1][j] == 1) cell--;
                    if (i + 1 < m && grid[i+1][j] == 1) cell--;
                    if (j > 0 && grid[i][j-1] == 1) cell--;
                    if (j + 1 < n && grid[i][j+1] == 1) cell--;
                    total += cell;
                }
            }
        }
        return total;
    }
};
