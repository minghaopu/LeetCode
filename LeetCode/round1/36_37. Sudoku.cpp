//
//  36. Valid Sudoku.cpp && 37 sudoku solver;
//  LeetCode
//
//  Created by roneil on 2016/11/27.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    short row[9], col[9], block[9];
    bool helper(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return helper(board, i + 1, 0);
        if (board[i][j] != '.') return helper(board, i, j+1);
        
        for (int ch = 1; ch <= 9; ch++) {
            int tmp = 1 << ch;
            if (!(row[i] & tmp) && !(col[j] & tmp) && !(block[i/3*3 + j/3] & tmp)) {
                row[i] |= tmp;
                col[j] |= tmp;
                block[i/3*3 + j/3] |= tmp;
                board[i][j] = ch + '0';
                if (helper(board, i, j+1)) return true;
                board[i][j] = '.';
                row[i] ^= tmp;
                col[j] ^= tmp;
                block[i/3*3 + j/3] ^= tmp;
            }
        }
        return false;
        
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col[9] = {0};
        int row[9] = {0};
        int block[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int index = 1 << (board[i][j] - '0');
                    if ((row[i] & index) || (col[j] & index) || (block[i / 3 * 3 + j / 3] & index)) return false;
                    row[i] |= index;
                    col[j] |= index;
                    block[i / 3 * 3 + j / 3] |= index;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        for (int i = 0; i < 9; i++) {
            for (int j = 0;j < 9; j++) {
                if (board[i][j] != '.') {
                    int tmp = 1 << (board[i][j] - '0');
                    row[i] |= tmp;
                    col[j] |= tmp;
                    block[i/3*3 + j/3] |= tmp;
                }
            }
        }
        helper(board, 0, 0);
        return;
    }
};
