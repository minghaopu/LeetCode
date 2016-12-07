//
//  221.cpp
//  LeetCode
//
//  Created by roneil on 12/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = (int) matrix.size(), n = (int) matrix[0].size(), maxLen = 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            if (dp[i][0] == 1) maxLen = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            if (dp[0][j] == 1) maxLen = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    maxLen = dp[i][j] > maxLen ? dp[i][j] : maxLen;
                } else {
                    dp[i][j] = 1;
                }
            }
        }
        return maxLen * maxLen;
    }
};
