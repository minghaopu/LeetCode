//
//  298.cpp
//  LeetCode
//
//  Created by neal on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<int> row, col;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());
        int r = (int) row.size(), c = (int) col.size();
        int midRow = (r & 1) ? row[r/2] : (row[r/2 - 1] + row[r/2]) / 2; // median
        int midCol = (c & 1) ? col[c/2] : (col[c/2 - 1] + col[c/2]) / 2; // median
        int dis = 0;
        for (int i = 0; i < r; i++) dis += abs(row[i] - midRow);
        for (int i = 0; i < c; i++) dis += abs(col[i] - midCol);
        return dis;
    }
};
