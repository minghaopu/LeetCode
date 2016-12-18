//
//  425.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    struct Node {
        vector<int> indices;
        Node* next[26];
        Node() {
            memset(next, NULL, sizeof(next));
        }
    };
    Node* buildTree(vector<string>& words) {
        Node* node = new Node();
        for (int i = 0; i < words.size(); i++) {
            Node* p = node;
            for (char c : words[i]) {
                int j = c - 'a';
                if (!p->next[j]) p->next[j] = new Node();
                p = p->next[j];
                p->indices.push_back(i);
            }
            
        }
        return node;
    }
    vector<vector<string>> res;
    vector<string> path;
    int avlength;
    Node* root;
    void helper(vector<string>& words, int level) {
        if (level == avlength) {
            res.push_back(path);
            return;
        }
        string str = "";
        for (int i = 0; i < level; i++) str += path[i][level];
        Node* p = root;
        for (char c : str) {
            int i = c - 'a';
            if (!p->next[i]) return;
            p = p->next[i];
        }
        for (int index : p->indices) {
            path[level] = words[index];
            helper(words, level + 1);
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return res;
        avlength = (int) words[0].size();
        root = buildTree(words);
        path.resize(avlength);
        for (string word : words) {
            path[0] = word;
            helper(words, 1);
        }
        return res;
    }
};
