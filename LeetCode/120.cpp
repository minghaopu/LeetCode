//
//  120.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = (int) triangle.size();
        vector<int> dp = triangle.back();
        for (int i = len - 2; i > -1; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
