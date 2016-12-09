//
//  289.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = (int) board.size(), n = (int) board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = countLives(board, i, j, m, n);
                if (board[i][j] == 1) {
                    if (lives < 2 || lives > 3) board[i][j] = 1; // 1 -> 0 die use '1(01)' for (1->0) means death;
                    else board[i][j] = 3; // 1->1 (11) stay alive;
                } else if (board[i][j] == 0) {
                    if (lives == 3) board[i][j] = 2; // 0->1 reproduction
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
    int countLives(vector<vector<int>>& board, int x, int y, int m, int n) {
        int count = -(board[x][y] & 1);
        for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); i++) {
            for (int j = max(y - 1, 0); j <= min(y + 1, n - 1); j++) {
                count += (board[i][j] & 1); // if board[i][j] = 1 then count + 1;
            }
        }
        return count;
    }
    
};
