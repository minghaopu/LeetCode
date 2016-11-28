//
//  51. N-Queens.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/27.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<vector<string>> res;
    vector<int> col;
    vector<int> dia;
    vector<int> ant;
    vector<string> board;
    int count;
public:
    /*
     *
     *      51. N-Queens
     *
     */
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        col.assign(n, 1);
        dia.assign(2* n - 1, 1);
        ant.assign(2 * n - 1, 1);
        dfs(0, n);
        return res;
    }
    void dfs (int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j != n; j++) {
            if (col[j] && dia[row + j] && ant[n - 1 + j - row]) {
                col[j] = dia[row + j] = ant[n - 1 + j - row] = 0;
                board[row][j] = 'Q';
                dfs(row + 1, n);
                board[row][j] = '.';
                col[j] = dia[row + j] = ant[n - 1 + j - row] = 1;
            }
        }
    }
    /*
     *
     *      52. N-Queens II
     *
     */
    int totalNQueens(int n) {
        count = 0;
        board.assign(n, string(n, '.'));
        col.assign(n, 1);
        dia.assign(2 * n - 1, 1);
        ant.assign(2 * n - 1, 1);
        dfs(0, n);
        return count;
    }
};
