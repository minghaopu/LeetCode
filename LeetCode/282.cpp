//
//  282.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if (num == "") return {};
        vector<string> res;
        helper(res, "", num, target, 0, 0, 0);
        return res;
    }
    void helper(vector<string>& res, string path, string num, int target, int start, long pre, long cur) { // long
        if (start == num.size()) {
            if (target == cur) res.push_back(path);
            return;
        }
        for (int i = start; i < num.size(); i++) {
            if (num[start] == '0' && i > start) break;
            string sub = num.substr(start, i - start + 1);
            long val = stol(sub);
            if (start == 0) {
                helper(res, sub, num, target, i + 1, val, val);
            } else {
                helper(res, path + '+' + sub, num, target, i + 1, val, cur + val);
                helper(res, path + '-' + sub, num, target, i + 1, -val, cur - val); // -val
                helper(res, path + '*' + sub, num, target, i + 1, pre * val, cur - pre + pre * val);
            }
        }
    }
};
