//
//  63.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        if (m == 0) return 0;
        int n = (int)obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == -1) break;
            obstacleGrid[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == -1) break;
            obstacleGrid[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == -1) continue;
                
                if (obstacleGrid[i][j-1] != -1) obstacleGrid[i][j] += obstacleGrid[i][j-1];
                if (obstacleGrid[i-1][j] != -1) obstacleGrid[i][j] += obstacleGrid[i-1][j];
            }
            
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (obstacleGrid[i][j] == -1) obstacleGrid[i][j] = 1;
        }
        return obstacleGrid[m-1][n-1];
    }
};
