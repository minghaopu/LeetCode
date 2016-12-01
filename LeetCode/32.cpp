//
//  32.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) return 0;
        int maxLength = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i - 2) >= 0 ? (dp[i-2] + 2) : 2;
                } else {
                    if (i - dp[i-1] - 1 >= 0 && s[i-dp[i-1]-1] == '(') {
                        
                        dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2 >=0) ? dp[i-dp[i-1]-2] : 0);
                    }
                }
                maxLength = max(maxLength, dp[i]);
            }
        }
        return maxLength;
    }
};
