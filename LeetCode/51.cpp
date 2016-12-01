//
//  51.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<bool> col;
    vector<bool> dia1;
    vector<bool> dia2;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return {};
        col.assign(n, false);
        dia1.assign(2 * n - 1, false);
        dia2.assign(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));
        helper(board, 0, n);
        return res;
    }
    void helper(vector<string> board, int i, int n) {
        if (i == n) {
            res.push_back(board);
            return;
        };
        for (int j = 0; j < n; j++) {
            if (col[j] || dia1[i + j] || dia2[n - i - 1 + j]) continue;
            board[i][j] = 'Q';
            col[j] = true;
            dia1[i+j] = true;
            dia2[n-i-1+j] = true;
            helper(board, i+1, n);
            board[i][j] = '.';
            col[j] = false;
            dia1[i+j] = false;
            dia2[n-i-1+j] = false;
        }
    }
};
