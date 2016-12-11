//
//  301.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<string> res;
    bool isValid(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
            else if (c == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
    void dfs(string s, int start, int left, int right) {
        if (left == 0 && right == 0) {
            if (isValid(s)) res.push_back(s);
        }
        for (int i = start; i < s.length(); i++) {
            if (i == start || s[i] != s[i-1]) {
                string tmp = s;
                if (right == 0 && left > 0 && tmp[i] == '(') {
                    tmp.erase(i, 1);
                    dfs(tmp, i, left - 1, right);
                } else if (right > 0 && tmp[i] == ')') {
                    tmp.erase(i, 1);
                    dfs(tmp, i, left, right - 1);
                }
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            left += c == '(';
            if (left == 0) {
                right += c == ')';
            } else {
                left -= c == ')';
            }
        }
        dfs(s, 0, left, right);
        return res;
    }
};
