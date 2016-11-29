//
//  301.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/27.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<string> res;
    bool isValid(string s) {
        int sum = 0;
        for (char c : s) {
            if (c == '(') sum++;
            else if (c == ')') sum--;
            if (sum < 0) return false;
        }
        return sum == 0;
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
    void dfs(string s, int begin, int left, int right) {
        if (left == 0 && right == 0) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        for (int i = begin; i < s.length(); i++) {
            string tmp = s;
            if (right == 0 && left > 0 && tmp[i] == '(') {
                if (i == begin || tmp[i] != tmp[i-1]) {
                    tmp.erase(i, 1);
                    dfs(tmp, i, left - 1, right);
                }
            }
            if (right > 0 && tmp[i] == ')') {
                if (i == begin || tmp[i] != tmp[i-1]) {
                    tmp.erase(i,1);
                    dfs(tmp, i, left, right - 1);
                }
            }
        }
    }
};
