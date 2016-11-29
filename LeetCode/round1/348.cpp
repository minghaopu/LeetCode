//
//  348.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//
#include "Header.h"
class TicTacToe {
private:
    vector<int> rowCount;
    vector<int> colCount;
    int dia;
    int antiDia;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int size) {
        n = size;
        rowCount.assign(n, 0);
        colCount.assign(n, 0);
        dia = 0;
        antiDia = 0;
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
            rowCount[row]++;
            colCount[col]++;
            if (row == col) dia++;
            if (row + col == n - 1) antiDia++;
            if (rowCount[row] == n || colCount[col] == n || dia == n || antiDia == n) return 1;
        } else {
            rowCount[row]--;
            colCount[col]--;
            if (row == col) dia--;
            if (row + col == n - 1) antiDia--;
            if (rowCount[row] == -n || colCount[col] == -n || dia == -n || antiDia == -n) return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
