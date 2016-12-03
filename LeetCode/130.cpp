//
//  130.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = (int) board.size(), n = (int) board[0].size();
        for (int i = 0; i < m; i++) {
            changeNotSurrounded(board, i, 0, m, n);
            if (n > 1) changeNotSurrounded(board, i, n-1, m, n);
        }
        for (int j = 0; j < n; j++) {
            changeNotSurrounded(board, 0, j, m, n);
            if (m > 1) changeNotSurrounded(board, m-1, j, m, n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '1') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    void changeNotSurrounded(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) changeNotSurrounded(board, i - 1, j, m, n);
            if (j > 1) changeNotSurrounded(board, i, j - 1, m, n);
            if (i < m - 1) changeNotSurrounded(board, i + 1, j, m, n);
            if (j < n - 1) changeNotSurrounded(board, i, j + 1, m, n);
        }
    }
};
