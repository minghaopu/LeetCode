
//
//  208.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class TrieNode {
public:
    // Initialize your data structure here.
    bool isWord = false;
    TrieNode *next[26];
    TrieNode() {
        memset(next, NULL, sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (char c : word) {
            int index = c - 'a';
            if (!p->next[index]) p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->next[i]) return false;
            p = p->next[i];
        }
        return p && p->isWord;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!p->next[i]) return false;
            p = p->next[i];
        }
        return p;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
