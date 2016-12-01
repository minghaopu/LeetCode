//
//  54.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        if (matrix.size() == 1) return matrix[0];
        int index = 0, m = (int)matrix.size(), n = (int)matrix[0].size();
        int left = 0, right = n-1, up = 0, down = m-1, i = 0, j = 0;
        vector<int> res(m*n, 0);
        while (index < m * n) {
            for (j = left, i = up; j <= right; j++) res[index++] = matrix[i][j];
            up++;
            if (index == m * n) break;
            for (i = up, j = right; i <= down; i++) res[index++] = matrix[i][j];
            right--;
            if (index == m * n) break;
            for (j = right, i = down; j >= left; j--) res[index++] = matrix[i][j];
            down--;
            if (index == m * n) break;
            for (i = down, j = left; i >= up; i--) res[index++] = matrix[i][j];
            left++;
        }
        return res;
    }
};
