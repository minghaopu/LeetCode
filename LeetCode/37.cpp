//
//  37.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    int row[9];
    int col[9];
    int block[9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int ch = 1 << (board[i][j] - '0');
                row[i] |= ch;
                col[j] |= ch;
                block[i/3*3 + j/3] |= ch;
            }
        }
        helper(board, 0, 0);
    }
    bool helper(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return helper(board, i + 1, 0);
        if (board[i][j] != '.') return helper(board, i, j+1);
        
        for (int shift = 1; shift <= 9; shift++) {
            int ch = (1 << shift);
            if (!(row[i] & ch) && !(col[j] & ch) && !(block[i/3*3 + j/3] & ch)) {
                board[i][j] = char('0' + shift);
                row[i] |= ch;
                col[j] |= ch;
                block[i/3*3 + j/3] |= ch;
                if(helper(board, i, j+1)) return true;
                board[i][j] = '.';
                row[i] ^= ch;
                col[j] ^= ch;
                block[i/3*3 + j/3] ^= ch;
            }
        }
        return false;
    }
};
