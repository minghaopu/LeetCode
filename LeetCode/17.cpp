//
//  17.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits == "") return {};
        vector<string> res (1, "");
        for(int i = 0; i < digits.size(); i++) {
            string add = board[digits[i] - '0'];
            if (add != "") {
                vector<string> tmp;
                for (int j = 0; j < res.size(); j++) {
                    for (char c : add) {
                        tmp.push_back(res[j] + c);
                    }
                }
                swap(tmp, res);
            }
        }
        return res;
    }
};
