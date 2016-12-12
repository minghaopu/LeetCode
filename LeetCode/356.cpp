//
//  356.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, int> cache;
        int minx = INT_MAX, maxx = INT_MIN;
        for (auto p : points) {
            minx = min(minx, p.first);
            maxx = max(maxx, p.first);
            cache[p.first] = p.second;
        }
        for (auto it = cache.begin(); it != cache.end(); it++) {
            int oppositx = (minx + maxx) - it->first;
            if (cache.find(oppositx) == cache.end() || cache[oppositx] != it->second) return false;
        }
        return true;
    }
};
