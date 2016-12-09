//
//  288_302_408_411.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class ValidWordAbbr {
private:
    unordered_map<string, set<string>> hash;
public:
    // 288
    ValidWordAbbr(vector<string> &dictionary) {
        for (string word : dictionary) {
            string abbr = word.length() > 2 ? (word.front() + to_string((int)word.length() - 2) + word.back()) : word;
            hash[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        if (word == "") return true;
        string abbr = word.length() > 2 ? (word.front() + to_string((int)word.length() - 2) + word.back()) : word;
        return hash.find(abbr) == hash.end() || hash[abbr].count(word) == hash[abbr].size();
    }
    // 320;
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(res, word, "", false, 0);
        return res;
    }
    void helper(vector<string>& res, string word, string path, bool isPreNum, int start) {
        if (start == word.length()) {
            res.push_back(path);
            return;
        }
        helper(res, word, path + word[start], false, start + 1);
        
        if (!isPreNum) {
            for (int i = 1; start + i <= word.length(); i++) {
                helper(res, word, path + to_string(i), true, start + i);
            }
        }
    }
    // 408
    bool validWordAbbreviation(string word, string abbr) {
        if (abbr.length() > word.length()) return false;
        int i = 0, j = 0, n = 0;
        while (i < word.length() && j < abbr.length()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                while (j < abbr.length() && isdigit(abbr[j])) n = n * 10 + abbr[j++] - '0';
                i += n;
                n = 0;
            } else {
                if (word[i] != abbr[j]) return false;
                i++;
                j++;
            }
        }
        return i == word.length() && j == abbr.length();
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
