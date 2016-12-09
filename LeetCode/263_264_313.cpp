//
//  263_264_313.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        while (num > 1) {
            if (num % 2 == 0) num = num / 2;
            else if (num % 3 == 0) num = num / 3;
            else if (num % 5 == 0) num = num / 5;
            else return false;
        }
        return true;
    }
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        int ptr2 = 1, ptr3 = 1, ptr5 = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[ptr2] * 2, min(dp[ptr3] * 3, dp[ptr5] * 5));
            if (dp[i] == dp[ptr2] * 2) ptr2++;
            if (dp[i] == dp[ptr3] * 3) ptr3++;
            if (dp[i] == dp[ptr5] * 5) ptr5++;
        }
        return dp[n];
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = (int) primes.size();
        vector<int> ptrs(len, 1);
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int tmp = INT_MAX;
            for (int j = 0; j < len; j++) {
                tmp = min(tmp, dp[ptrs[j]] * primes[j]);
            }
            for (int j = 0; j < len; j++) {
                if (dp[ptrs[j]] * primes[j] == tmp) ptrs[j]++;
            }
            dp[i] = tmp;
        }
        
        return dp[n];
    }
};
