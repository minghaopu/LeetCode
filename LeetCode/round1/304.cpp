//
//  304.cpp
//  LeetCode
//
//  Created by roneil on 11/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//
#include "Header.h"
class NumMatrix {
private:
    vector<vector<int>> sums;
    int a(int i, int j) {
        return i < 0 || j < 0 ? 0 : sums[i][j];
    }
public:
    NumMatrix(vector<vector<int>> &matrix) {
        sums = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sums[i][j] += a(i,j-1) + a(i-1,j) - a(i-1,j-1);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return a(row2, col2) - a(row1-1, col2) - a(row2, col1-1) + a(row1-1, col1-1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
