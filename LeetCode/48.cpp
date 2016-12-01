//
//  48.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        if (n == 1) return;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int j = 0; j < n/2; j++) {
            for (int i = 0; i < n; i++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
