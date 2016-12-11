//
//  322.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int l = (int) coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < l; j++) {
                if (i >= coins[j]) dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
class Solution_TLE {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end(), [](const int a, const int b) {return a > b;});
        int res = INT_MAX;
        dfs(coins, amount, 0, res);
        return res == INT_MAX ? -1 : (int)res;
    }
    void dfs(vector<int>& coins, int amount, int count, int& res) {
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] > amount) continue;
            for (int l = amount / coins[i]; l > 0; l--) {
                int rest = amount - l * coins[i];
                if (rest == 0) {
                    res = min(count + l, res);
                    return;
                } else if (rest < coins.back()) continue;
                else dfs(coins, rest, count + l, res);
            }
        }
    }
};
