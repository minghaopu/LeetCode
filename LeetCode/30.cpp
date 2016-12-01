//
//  30.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cache;
        for (string word : words) cache[word]++;
        int len = (int)words[0].size();
        int size = (int)words.size();
        vector<int> res;
        for (int i = 0; i <= (int)s.length() - len * size; i++) {
            unordered_map<string, int> window;
            int j = 0;
            while (j < size) {
                string word = s.substr(i + j * len, len);
                if (cache.find(word) != cache.end()) {
                    window[word]++;
                    if (window[word] > cache[word]) break;
                } else break;
                j++;
            }
            if (j == size) res.push_back(i);
        }
        return res;
    }
};
