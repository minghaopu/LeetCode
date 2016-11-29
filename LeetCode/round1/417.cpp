//
//  417.cpp
//  LeetCode
//
//  Created by roneil on 11/17/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = int(matrix.size());
        if (m == 0) return {};
        int n = int(matrix[0].size());
        vector<vector<bool>> pm(m, vector<bool> (n, false)), am(m, vector<bool> (n, false));
        vector<pair<int, int>> res;
        stack<pair<int, int>> sp;
        stack<pair<int, int>> sa;
        for (int i = 0; i < m; i++) {
            int j = m - i - 1;
            pm[i][0] = true;
            sp.push({i, 0});
            am[j][n-1] = true;
            sa.push({j, n-1});
        }
        for (int i = 0; i < n; i++) {
            int j = n - i - 1;
            pm[0][i] = true;
            sp.push({0, i});
            am[m-1][j] = true;
            sa.push({m-1, j});
        }
        
        sp.push({0,0});
        sa.push({m-1, n-1});
        while(!sp.empty()){
            pair<int, int> index=sp.top();
            int x=index.first;
            int y=index.second;
            sp.pop();
            if (x-1 >= 0 && !pm[x-1][y] && matrix[x-1][y] >= matrix[x][y]){
                sp.push({x-1,y});
                pm[x-1][y] = true;
            }
            if (x+1 < m && !pm[x+1][y] && matrix[x+1][y] >= matrix[x][y]){
                sp.push({x+1,y});
                pm[x+1][y] = true;
            }
            if (y-1 >= 0 && !pm[x][y-1] && matrix[x][y-1] >= matrix[x][y]){
                sp.push({x,y-1});
                pm[x][y-1] = true;
            }
            if (y+1 < n && !pm[x][y+1] && matrix[x][y+1] >= matrix[x][y]){
                sp.push({x,y+1});
                pm[x][y+1] = true;
            }
        }
        while(!sa.empty()){
            pair<int, int> index=sa.top();
            int x=index.first;
            int y=index.second;
            sa.pop();
            if (x-1 >= 0 && !am[x-1][y] && matrix[x-1][y] >= matrix[x][y]){
                sa.push({x-1,y});
                am[x-1][y] = true;
            }
            if (x+1 < m && !am[x+1][y] && matrix[x+1][y] >= matrix[x][y]){
                sa.push({x+1,y});
                am[x+1][y] = true;
            }
            if (y-1 >= 0 && !am[x][y-1] && matrix[x][y-1] >= matrix[x][y]){
                sa.push({x,y-1});
                am[x][y-1] = true;
            }
            if (y+1 < n && !am[x][y+1] && matrix[x][y+1] >= matrix[x][y]){
                sa.push({x,y+1});
                am[x][y+1] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (am[i][j] && pm[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
