//
//  413_446.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    typedef unordered_map<int, int> um;
public:
    int numberOfArithmeticSlicesI(vector<int>& A) {
        int n = (int) A.size();
        if (n < 3) return 0;
        int dp[n];
        int res = 0;
        memset(dp, 0, sizeof(int) * n);
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp[i] = dp[i-1] + 1;
            }
            res += dp[i];
        }
        return res;
    }
    int numberOfArithmeticSlicesII(vector<int>& A) {
        if (A.empty()) return 0;
        int n = (int) A.size();
        um *hash = new um[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
                int dif = A[i] - A[j];
                hash[i][dif]++;
                if (hash[j].find(dif) != hash[j].end()) {
                    hash[i][dif] += hash[j][dif];
                    res += hash[j][dif];
                }
            }
        }
        return res;
    }
};
