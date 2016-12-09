//
//  411.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_set<string> cache;
public:
    // tle
    string minAbbreviation(string target, vector<string>& dictionary) {
        for (string s : dictionary) {
            vector<pair<int,string>> tmp = generateAbbreviations(s);
            for (auto p : tmp) {
                cache.insert(p.second);
            }
        }
        vector<pair<int,string>> tmp = generateAbbreviations(target);
        sort(tmp.begin(), tmp.end(), [](const pair<int,string> a, const pair<int,string> b) {return a.first < b.first;});
        for (auto p : tmp) {
            if (cache.find(p.second) == cache.end()) return p.second;
        }
        return "";
    }
    vector<pair<int, string>> generateAbbreviations(string word) {
        vector<pair<int, string>> res;
        helper(res, word, "", false, 0, (int)word.length());
        return res;
    }
    void helper(vector<pair<int,string>>& res, string word, string path, bool isPreNum, int start, int len) {
        if (start == word.length()) {
            res.push_back({len, path});
            return;
        }
        helper(res, word, path + word[start], false, start + 1, len);
        
        if (!isPreNum) {
            for (int i = 1; start + i <= word.length(); i++) {
                helper(res, word, path + to_string(i), true, start + i, len - i + 1);
            }
        }
    }
};
