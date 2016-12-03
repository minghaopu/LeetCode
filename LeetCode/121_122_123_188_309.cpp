//
//  121_122_123_188_309.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxProfit_one_transaction(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int sum = 0, profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int change = prices[i] - prices[i-1];
            sum = max(sum + change, change);// 5 - 1, 3 - 5 + 5 - 1, 6 - 3 + 3 - 5 + 5 - 1 = 6 - 1
            profit = max(profit, sum);
        }
        return profit;
    }
    int maxProfit_no_limits_transation(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0, change;
        for (int i = 1; i < prices.size(); i++) {
            change = prices[i] - prices[i-1];
            if (change > 0) profit += change;
        }
        return profit;
    }
    int maxProfit_two_transaction(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            sell2 = max(sell2, buy2 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy1 = max(buy1, -prices[i]);
        }
        return sell2;
    }
    int maxProfit_k_transaction(int k, vector<int>& prices) {
        int n = (int) prices.size();
        if (prices.size()  < 2) return 0;
        if (k >= n / 2) {
            int sum = 0;
            for (int i = 1; i < n; i++) {
                if(prices[i] > prices[i-1]){
                    sum += prices[i] - prices[i-1];
                }
            }
            return sum;
        }
        int buys[k+1], sells[k+1];
        for (int i = 0; i <= k; i++) {
            buys[i] = INT_MIN;
            sells[i] = 0;
        }
        for (int p : prices) {
            for (int i = k; i > 0; i--) {
                sells[i] = max(sells[i], buys[i] + p);
                buys[i] = max(buys[i], sells[i-1] - p);
            }
        }
        return sells[k];
    }
    int maxProfit_no_limit_but_with_Cooldown(vector<int>& prices) {
        int n = (int)prices.size();
        if (n < 2) return 0;
        int profit = 0;
        vector<int> sells(n, 0);
        vector<int> buys(n, 0);
        buys[0] = -prices[0];
        buys[1] = -prices[1];
        for (int i = 1; i < n; i++) {
            sells[i] = max(buys[i-1] + prices[i], sells[i-1] - prices[i-1] + prices[i]);
            if (sells[i] > profit) profit = sells[i];
            if (i > 1) buys[i] = max(sells[i-2] - prices[i], buys[i-1] + prices[i-1] - prices[i]);
        }
        return profit;
    }
};
