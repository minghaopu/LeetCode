
//
//  218.cpp
//  LeetCode
//
//  Created by roneil on 12/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>> Q;
        int cur = 0, curX, curH, len = (int) buildings.size();
        while (cur < len || !Q.empty()) {
            curX = Q.empty() ? buildings[cur][0] : Q.top().second;
            if (cur >= len || buildings[cur][0] > curX) {
                while (!Q.empty() && Q.top().second <= curX) Q.pop();
            } else {
                curX = buildings[cur][0];
                while (cur < len && buildings[cur][0] == curX) {
                    Q.push({buildings[cur][2], buildings[cur][1]});
                    cur++;
                }
            }
            curH = Q.empty() ? 0 : Q.top().first;
            if (res.empty() || (res.back().second != curH)) res.push_back({curX, curH});
        }
        return res;
    }
};
