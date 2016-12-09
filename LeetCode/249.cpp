//
//  249.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<int, vector<string>> hash;
        vector<vector<string>> res;
        for (string word : strings) {
            int num = 1;
            for (int i = 1; i < word.length(); i++) {
                int j = (word[i] - word[i-1]);
                if (j < 0) j = j + 26;
                num = num * 26 + j;
            }
            hash[num].push_back(word);
        }
        for (auto it : hash) {
            res.push_back(it.second);
        }
        return res;
    }
};
