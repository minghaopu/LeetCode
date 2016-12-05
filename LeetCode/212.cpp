//
//  212.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h" 
class Solution {
private:
    struct TrieNode {
        TrieNode *next[26];
        bool isWord = false;
        int index = 0;
        TrieNode () {
            memset(next, NULL, sizeof(next));
        }
    };
    TrieNode *root;
    void insert(string word, int index) {
        TrieNode *p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->next[i]) p->next[i] = new TrieNode();
            p = p->next[i];
        }
        p->isWord = true;
        p->index = index;
    }
    void buildTree(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }
    }
    void dfs(TrieNode* node, vector<vector<char>>& board, vector<string>& words, int i, int j) {
        if (node->isWord) {
            res.push_back(words[node->index]);
            node->isWord = false;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*' || !node->next[board[i][j]-'a']) return;
        int c = board[i][j] - 'a';
        board[i][j] = '*';
        dfs(node->next[c], board, words, i + 1, j);
        dfs(node->next[c], board, words, i - 1, j);
        dfs(node->next[c], board, words, i, j + 1);
        dfs(node->next[c], board, words, i, j - 1);
        board[i][j] = 'a' + c;
    }
    vector<string> res;
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty() || board.empty() || board[0].empty()) return res;
        root = new TrieNode();
        buildTree(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(root, board, words, i, j);
            }
        }
        return res;
    }
    
};
