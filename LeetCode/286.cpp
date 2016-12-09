
//
//  286.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int row = (int) rooms.size();
        int col = (int) rooms[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rooms[i][j] == 0) q.push({i, j});
            }
        }
        while (!q.empty()) {
            auto cord = q.front();
            q.pop();
            int i = cord.first, j = cord.second;
            for (auto dir : dirs) {
                int x = i + dir.first, y = j + dir.second;
                if (x < 0 || y < 0 || x >= row || y >= col || rooms[x][y] <= rooms[i][j] + 1) continue;
                rooms[x][y] = rooms[i][j] + 1;
                q.push({x, y});
            }
        }
    }
};
