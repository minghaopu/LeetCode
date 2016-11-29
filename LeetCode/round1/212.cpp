//
//  212.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    class TrieNode {
    public:
        TrieNode* next[26];
        bool isWord;
        int index;
        TrieNode() {
            memset(next, NULL, sizeof(next));
            isWord = false;
            index = -1;
        }
    };
    TrieNode* root;
    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty() || board.empty() || board[0].empty()) return res;
        root = new TrieNode();
        buildTree(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs212(root, board, words, i, j);
            }
        }
        delete root;
        return res;
    }
    void insert(string word, int index) {
        TrieNode* p = root;
        for (int i = 0; i < word.length(); i++) {
            if (p->next[word[i] - 'a'] == NULL) p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->index = index;
        p->isWord = true;
    }
    void buildTree(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }
    }
    void dfs212(TrieNode* node, vector<vector<char>>& board, vector<string>& words, int row, int col) {
        if (node->isWord) {
            res.push_back(words[node->index]);
            node->isWord = false;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '*' || !node->next[board[row][col]-'a']) return;
        int c = board[row][col]-'a';
        board[row][col] = '*';
        dfs212(node->next[c], board, words, row+1, col);
        dfs212(node->next[c], board, words, row, col+1);
        dfs212(node->next[c], board, words, row-1, col);
        dfs212(node->next[c], board, words, row, col-1);
        board[row][col] = char('a' + c);
    }
};
