//
//  131_132.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(res, path, s, 0);
        return res;
    }
    void dfs (vector<vector<string>>& res, vector<string> path, string s, int index) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (isParlindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(res, path, s, i+1);
                path.pop_back();
            }
        }
    }
    bool isParlindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    int minCut(string s) {
        int l = (int) s.length();
        int minCuts[l+1];
        iota(minCuts, minCuts+l+1, -1);
        bool isPal[l][l];
        fill_n(&isPal[0][0], l*l, false);
        for (int j = 1; j < l; j++) {
            for (int i = j; i >= 0; i--) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);
                }
            }
        }
        return minCuts[l];
    }
};
