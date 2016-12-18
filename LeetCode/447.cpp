//
//  447.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (auto & p1 : points) {
            unordered_map<int, int> cache;
            for (auto p2 : points) {
                cache[getDistance(p1, p2)]++;
            }
            for (auto it = cache.begin(); it != cache.end(); it++) res += it->second * (it->second - 1);
        }
        return res;
    }
    int getDistance(pair<int, int>& a, pair<int, int>& b) {
        return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    }
};
