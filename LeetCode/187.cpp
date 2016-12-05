//
//  187.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        unordered_map<string, int> hash;
        vector<string> res;
        for (int i = 0; i <= s.length() - 10; i++) {
            string tmp = s.substr(i, 10);
            hash[tmp]++;
            if (hash[tmp] == 2) res.push_back(tmp);
        }
        return res;
    }
};
