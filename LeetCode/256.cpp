//
//  256.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int len = (int) costs.size();
        for (int i = 1; i < len; i++) {
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][1], costs[i-1][0]);
        }
        return min(costs[len - 1][0], min(costs[len - 1][1], costs[len - 1][2]));
    }
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int len = (int) costs.size(), colors = (int) costs[0].size();
        for (int i = 1; i < len; i++) {
            vector<int> last = costs[i-1];
            sort(last.begin(), last.end());
            for (int j = 0; j < colors; j++) {
                int k = 0;
                if (costs[i-1][j] == last[k]) k++;
                costs[i][j] += last[k];
            }
        }
        int minCost = INT_MAX;
        for (int n : costs[len-1]) {
            if (minCost > n) minCost = n;
        }
        return minCost;
    }
};
