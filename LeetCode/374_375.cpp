//
//  374_375.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, mid, res;
        while (l <= n) {
            mid = l + (n - l) / 2;
            res = guess(mid);
            if (res == 0) return mid;
            else if (res == 1) l = mid + 1;
            else n = mid - 1;
        }
        return 0;
    }
    int getMoneyAmount(int n) {
        int dp[n+1][n+1];
        fill_n(&dp[0][0], (n+1)*(n+1), 0);
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j > -1; j--) {
                if (j + 1 == i) dp[j][i] = j;
                else {
                    int tmp = INT_MAX;
                    for (int k = j + 1; k < i; k++) {
                        tmp = min(max(dp[j][k-1], dp[k+1][i]) + k, tmp);
                    }
                    dp[j][i] = tmp;
                }
            }
        }
        return dp[1][n];
    }
};
