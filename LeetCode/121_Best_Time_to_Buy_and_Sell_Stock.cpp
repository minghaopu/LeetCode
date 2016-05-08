//
//  121_Best_Time_to_Buy_and_Sell_Stock.cpp
//  LeetCode
//
//  Created by roneil on 16/5/8.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"


class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int bestBuy = INT_MAX;
    //     int maxProfit = 0;
    //     for (int i = 0; i < prices.size(); i++) {
    //         if (bestBuy > prices[i]) bestBuy = prices[i];
    //         else if (prices[i] - bestBuy > maxProfit) maxProfit = prices[i] - bestBuy;
    //     }
    //     return maxProfit;
    // }
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if (l < 2) return 0;
        
        int sum = 0, maxProfit = 0;
        for (int i = 1; i < l; i++) {
            int change = prices[i] - prices[i - 1];
            sum = max(sum + change, change); //choose the cumulate changes or one day change;
            maxProfit = max(maxProfit, sum);
        }
        return maxProfit;
    }
};