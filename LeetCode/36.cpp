//
//  36.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int block[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = 1 << (board[i][j] - '0'); //mask
                    if ((row[i] & num) || (col[j] & num) || (block[i/3*3 + j/3] & num)) return false;
                    row[i] |= num;
                    col[j] |= num;
                    block[i/3*3 + j/3] |= num;
                }
            }
        }
        return true;
    }
};
