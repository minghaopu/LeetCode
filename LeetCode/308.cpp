//
//  308.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
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
            for (int j = 1; j < matrix[0].size(); j++) {
                sums[i][j] +=  sums[i][j-1];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int dif = a(row, col-1) + val - sums[row][col];
        
        for (int j = col; j < sums[0].size(); j++) {
            sums[row][j] += dif;
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += sums[i][col2] - a(i, col1-1);
        }
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
