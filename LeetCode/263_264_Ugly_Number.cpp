//
//  263_Ugly_Number.cpp
//  LeetCode
//
//  Created by roneil on 16/4/25.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    Solution(){};
    bool isUgly(int num) {
        if (num == 1) return true;
        if (num <= 0) return false;
        while (num>1) {
            if (num%2 == 0) num = num/2;
            else if (num%3 == 0) num = num/3;
            else if (num%5 == 0) num = num/5;
            else return false;
        }
        return true;
    }
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        vector<int> dp (n + 1);
        int ptr2 = 1, ptr3 = 1, ptr5 = 1;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[ptr2] * 2, min(dp[ptr3] * 3, dp[ptr5] * 5));
            if (dp[i] == dp[ptr2] * 2) ptr2++;
            if (dp[i] == dp[ptr3] * 3) ptr3++;
            if (dp[i] == dp[ptr5] * 5) ptr5++;
        }
        return dp[n];
    }
};
