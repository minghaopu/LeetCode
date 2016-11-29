//
//  131.cpp
//  LeetCode
//
//  Created by roneil on 11/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/*
 *
 *     131. Palindrome Partitioning
 *
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty()) return result;
        vector<string> path;
        dfs(s, 0, path, result);
        return result;
    }
    void dfs(string s, int index, vector<string>& path, vector<vector<string>>& result) {
        if (index == s.length()) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (isPalindrom(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, path, result);
                path.pop_back();
            }
        }
    }
    bool isPalindrom(string s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
