//
//  84.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int res = 0, height, width;
        stack<int> S;
        for (int i = 0; i < heights.size(); i++) {
            if (S.empty() || heights[S.top()] < heights[i]) S.push(i);
            else {
                while (!S.empty() && heights[S.top()] >= heights[i]) {
                    height = heights[S.top()];
                    S.pop();
                    width = S.empty() ? i : i - (S.top() + 1);
                    res = max(res, height * width);
                }
                S.push(i);
            }
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, height, width;
        int m = (int)matrix.size(), n = (int) matrix[0].size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) dp[j] = matrix[i][j] - '0';
                else if (matrix[i][j] != '0') dp[j]++;
                else dp[j] = 0;
            }
            stack<int> st;
            for (int j = 0; j < n + 1; j++) {
                while (!st.empty() && dp[st.top()] >= dp[j]) {
                    height = dp[st.top()];
                    st.pop();
                    width = st.empty() ? j : j - (st.top() + 1);
                    res = max(res, height * width);
                }
                st.push(j);
            }
        }
        return res;
    }
};
