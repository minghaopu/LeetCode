//
//  52.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    int* col;
    int* dia1;
    int* dia2;
public:
    int totalNQueens(int n) {
        if (n < 2) return n;
        col = new int[n];
        memset(col, 0, sizeof(int) * n);
        dia1 = new int[2 * n - 1];
        memset(dia1, 0, sizeof(int) * (2*n-1));
        dia2 = new int[2 * n - 1];
        memset(dia2, 0, sizeof(int) * (2*n-1));
        
        vector<string> board(n, string(n, '.'));
        int total = 0;
        helper(board, 0, n, total);
        return total;
    }
    void helper(vector<string> board, int i, int n, int& total) {
        if (i == n) total++;
        else {
            for (int j = 0; j < n; j++) {
                if (col[j] || dia1[i+j] || dia2[n-i-1+j]) continue;
                board[i][j] = 'Q';
                col[j] = dia1[i+j] = dia2[n-i-1+j] = 1;
                helper(board, i + 1, n, total);
                col[j] = dia1[i+j] = dia2[n-i-1+j] = 0;
            }
        }
    }
};
