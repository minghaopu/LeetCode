//
//  417.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = (int) matrix.size(), n = (int) matrix[0].size();
        int pm[m][n];
        fill_n(&pm[0][0], m * n, false);
        int am[m][n];
        fill_n(&am[0][0], m * n, false);
        queue<pair<int, int>> pq; // next point for pacific bfs;
        queue<pair<int, int>> aq; // next point for atlantic bfs;
        for (int i = 0; i < m; i++) {
            int j = m - i - 1;
            pm[i][0] = true;
            pq.push({i, 0});
            am[j][n-1] = true;
            aq.push({j, n-1});
        }
        for (int i = 0; i < n; i++) {
            int j = n - i - 1;
            pm[0][i] = true;
            pq.push({0, i});
            am[m-1][j] = true;
            aq.push({m-1, j});
        }
        while (!pq.empty()) {
            pair<int, int> point = pq.front();
            int x = point.first, y = point.second;
            pq.pop();
            if (x-1 >= 0 && !pm[x-1][y] && matrix[x-1][y] >= matrix[x][y]) {
                pq.push({x-1, y});
                pm[x-1][y] = true;
            }
            if (x+1 < m && !pm[x+1][y] && matrix[x+1][y] >= matrix[x][y]) {
                pq.push({x+1, y});
                pm[x+1][y] = true;
            }
            if (y-1 >= 0 && !pm[x][y-1] && matrix[x][y-1] >= matrix[x][y]) {
                pq.push({x, y-1});
                pm[x][y-1] = true;
            }
            if (y+1 < n && !pm[x][y+1] && matrix[x][y+1] >= matrix[x][y]) {
                pq.push({x, y+1});
                pm[x][y+1] = true;
            }
        }
        while (!aq.empty()) {
            pair<int, int> point = aq.front();
            int x = point.first, y = point.second;
            aq.pop();
            if (x-1 >= 0 && !am[x-1][y] && matrix[x-1][y] >= matrix[x][y]) {
                aq.push({x-1, y});
                am[x-1][y] = true;
            }
            if (x+1 < m && !am[x+1][y] && matrix[x+1][y] >= matrix[x][y]) {
                aq.push({x+1, y});
                am[x+1][y] = true;
            }
            if (y-1 >= 0 && !am[x][y-1] && matrix[x][y-1] >= matrix[x][y]) {
                aq.push({x, y-1});
                am[x][y-1] = true;
            }
            if (y+1 < n && !am[x][y+1] && matrix[x][y+1] >= matrix[x][y]) {
                aq.push({x, y+1});
                am[x][y+1] = true;
            }
        }
        vector<pair<int, int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (am[i][j] && pm[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
