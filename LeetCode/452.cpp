//
//  452.cpp
//  LeetCode
//
//  Created by neal on 12/19/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int count = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for (int i = 0; i < points.size(); i++) {
            if (arrow != INT_MIN && points[i].first <= arrow) continue;
            arrow = points[i].second;
            count++;
        }
        return count;
    }
};
class SolutionII {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int count = 0, pre = 0, i = 0;
        sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        while (i < points.size()) {
            count++;
            pre = points[i].second;
            i++;
            while (pre >= points[i].first && i < points.size()) i++;
        }
        return count;
    }
};
