//
//  79.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int start, int i, int j) {
        if (start == word.length()) return true;
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) return false;
        if (board[i][j] == '*' || board[i][j] != word[start]) return false;
        
        char tmp = board[i][j];
        board[i][j] = '*';
        bool res = false;
        if (!res) res = dfs(board, word, start + 1, i + 1, j);
        if (!res) res = dfs(board, word, start + 1, i, j + 1);
        if (!res) res = dfs(board, word, start + 1, i - 1, j);
        if (!res) res = dfs(board, word, start + 1, i, j - 1);
        
        board[i][j] = tmp;
        
        return res;
    }
};
