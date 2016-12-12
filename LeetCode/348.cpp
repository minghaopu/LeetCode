//
//  348.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class TicTacToe {
private:
    vector<int> rows, cols;
    int diagonal1, diagonal2;
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        rows.assign(n, 0);
        cols.assign(n, 0);
        diagonal1 = diagonal2 = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
     @param row The row of the board.
     @param col The column of the board.
     @param player The player, can be either 1 or 2.
     @return The current winning condition, can be either:
     0: No one wins.
     1: Player 1 wins.
     2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            rows[row]++;
            cols[col]++;
            if (row == col) diagonal1++;
            if (row + col == size - 1) diagonal2++;
            if (rows[row] == size || cols[col] == size || diagonal1 == size || diagonal2 == size) return 1;
        } else {
            rows[row]--;
            cols[col]--;
            if (row == col) diagonal1--;
            if (row + col == size - 1) diagonal2--;
            if (rows[row] == -size || cols[col] == -size || diagonal1 == -size || diagonal2 == -size) return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
