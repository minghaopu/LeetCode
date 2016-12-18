//
//  474.cpp
//  LeetCode
//
//  Created by neal on 12/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        fill_n(&dp[0][0], (m+1) * (n+1), 0);
        int nZero, nOne;
        for (string& s : strs) {
            nZero = nOne = 0;
            for (char c : s) c == '0' ? nZero++ : nOne++;
            for (int i = m; i >= nZero; i--) {
                for (int j = n; j >= nOne; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-nZero][j-nOne] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
