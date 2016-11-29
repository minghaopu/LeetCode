//
//  351. Android Unlock Patterns.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<vector<int>> skip;
    vector<int> visited;
public:
    int numberOfPatterns(int m, int n) {
        skip.assign(10, vector<int> (10, 0));
        visited.assign(10, false);
        skip[1][3] = skip[3][1] = 2;
        skip[7][9] = skip[9][7] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[4][6] = skip[6][4] = skip[2][8] = skip[8][2] = skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = 5;
        
        int res = 0;
        for (int i = m; i <= n; i++) {
            res += dfs(i - 1, 1) * 4;
            res += dfs(i - 1, 2) * 4;
            res += dfs(i - 1, 5);
        }
        return res;
        
    }
    int dfs(int length, int pos) {
        if (length == 0) {
            return 1;
        }
        visited[pos] = true;
        int res = 0;
        int t = 0;
        for (int i = 1; i <= 9; i++) {
            
            if (!visited[i] && (skip[pos][i] == 0 || visited[skip[pos][i]])) {
                res += dfs(length - 1, i);
            }
        }
        visited[pos] = false;
        return res;
    }
};
