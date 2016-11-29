//
//  208.cpp
//  LeetCode
//
//  Created by roneil on 11/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class TrieNode {
public:
    bool isWord;
    TrieNode* next[26];
    TrieNode () {
        memset(next, NULL, sizeof(next));
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie () {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] == NULL) p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isWord = true;
    }
    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] != NULL) p = p->next[index];
            else return false;
        }
        return p != NULL && p->isWord;
    }
    bool searchPrefix(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (p->next[index] != NULL) p = p->next[index];
            else return false;
        }
        return p != NULL;
    }
};