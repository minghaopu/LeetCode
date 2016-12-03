//
//  139_140.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_map<string, vector<string>> hash;
    vector<string> combine(string word, vector<string> prev) {
        for(int i = 0; i < prev.size(); i++) prev[i] += ' ' + word;
        return prev;
    }
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.empty()) return false;
        int l = (int)s.size();
        bool dp[l + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= l; i++) {
            for (int j = i-1; j>= 0; j--) {
                if (dp[j]) {
                    string word = s.substr(j,i-j);
                    if (wordDict.find(word) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[l];
    }
    vector<string> wordBreak2_TLE(string s, unordered_set<string>& wordDict) {
        if (wordDict.empty()) return {};
        int l = (int) s.length();
        vector<vector<string>> dp(l+1);
        if (wordDict.find(s) != wordDict.end()) {
            dp[l].push_back(s);
            wordDict.erase(s);
        }
        dp[0].push_back("");
        for (int i = 1; i <= l; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (!dp[j].empty()) {
                    string tmp = s.substr(j, i-j);
                    if (wordDict.find(tmp) != wordDict.end()) {
                        for (int k = 0; k < dp[j].size(); k++) {
                            if (dp[j][k] == "") dp[i].push_back(tmp);
                            else dp[i].push_back(dp[j][k] + ' ' + tmp);
                        }
                    }
                }
            }
        }
        return dp[l];
    }
    vector<string> wordBreak2_ACT(string s, unordered_set<string>& wordDict) {
        if (hash.find(s) != hash.end()) return hash[s];
        vector<string> res;
        if (wordDict.find(s) != wordDict.end()) res.push_back(s);
        for (int i = 1; i < s.size(); i++) {
            string word = s.substr(i);
            if (wordDict.find(word) != wordDict.end()) {
                string remain = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak2_ACT(remain, wordDict));
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        hash[s] = res;
        return res;
    }
};
