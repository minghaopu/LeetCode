//
//  336. Palindrome Pairs.cpp
//  LeetCode
//
//  Created by roneil on 11/23/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    struct TrieNode {
        vector<int> indexList;
        int index;
        TrieNode* next[26];
        TrieNode() {
            index = -1;
            memset(next, NULL, sizeof(next));
        }
    };
    TrieNode* root;
    vector<vector<int>> res;
public:
    void insert(string word, int index) {
        TrieNode* p = root;
        for (int i = int(word.size()) - 1; i > -1; i--) {
            int j = word[i] - 'a';
            if (p->next[j] == NULL) p->next[j] = new TrieNode();
            if (isPalindrome(word, 0, i)) p->indexList.push_back(index);
            p = p->next[j];
        }
        p->index = index;
        p->indexList.push_back(index);
    }
    void search(string word, int index) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int j = word[i] - 'a';
            if (p->index != - 1 && p->index != index && isPalindrome(word, i, word.length()-1)) {
                res.push_back({index, p->index});
            }
            p = p->next[j];
            if (!p) return;
        }
        for (int i : p->indexList) {
            if (i == index) continue;
            res.push_back({index, i});
        }
    }
    bool isPalindrome(string word, int i, int j) {
        while (i < j) {
            if (word[i++] != word[j--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) insert(words[i], i);
        for (int i = 0; i < words.size(); i++) search(words[i], i);
        return  res;
    }
};
