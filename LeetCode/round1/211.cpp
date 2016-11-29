//
//  211.cpp
//  LeetCode
//
//  Created by roneil on 11/17/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class WordDictionary {
private:
    struct TrieNode {
        TrieNode* next[26];
        bool isWord;
        TrieNode(): isWord(false) {
            memset(next, NULL, sizeof(next));
        }
    };
    TrieNode* _root;
    bool search(string word, int start, TrieNode* node) {
        if (start == word.length()) return node->isWord;
        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                if(node->next[i] && search(word, start + 1, node->next[i])) return true;
            }
        } else {
            if (node->next[word[start] - 'a'] == NULL) return false;
            else return search(word, start + 1, node->next[word[start] - 'a']);
        }
        return false;
    }
public:
    WordDictionary () {
        _root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = _root;
        for (int i = 0; i < word.length(); i++) {
            if (p->next[word[i] - 'a'] == NULL) p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, _root);
    }
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
