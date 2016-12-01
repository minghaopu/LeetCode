//
//  73.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        
        vector<int> col(n, 1), row(m, 1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] &= (matrix[i][j] != 0);
                col[j] &= (matrix[i][j] != 0);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 0 || col[j] == 0) matrix[i][j] = 0;
            }
        }
    }
};
