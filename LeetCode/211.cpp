//
//  211.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class WordDictionary {
private:
    struct TrieNode {
        TrieNode *next[26];
        bool isWord = false;
        TrieNode () {
            memset(next, NULL, sizeof(next));
        }
    };
    TrieNode *root;
    bool search(string word, int start, TrieNode* node) {
        if (start == word.length()) return node->isWord;
        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->next[i] && search(word, start + 1, node->next[i])) return true;
            }
        } else {
            int index = word[start] - 'a';
            if (!node->next[index]) return false;
            else return search(word, start + 1, node->next[index]);
        }
        return false;
    }
public:
    WordDictionary () {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode*p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->next[i]) p->next[i] = new TrieNode();
            p = p->next[i];
        }
        p->isWord = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
