//
//  22.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
    void helper(vector<string>& res, string path, int left, int right) {
        if (left == 0 && right == 0) res.push_back(path);
        if (left > 0) helper(res, path + '(', left - 1, right + 1);
        if (right > 0) helper(res, path + ')', left, right - 1);
    }
};
