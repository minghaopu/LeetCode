//
//  49.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> cache;
        for (string word:strs) {
            string tmp = word;
            sort(tmp.begin(), tmp.end());
            cache[tmp].push_back(word);
        }
        vector<vector<string>> res;
        for (auto it = cache.begin(); it != cache.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
