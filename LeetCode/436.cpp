//
//  436.cpp
//  LeetCode
//
//  Created by neal on 12/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> cache;
        vector<int> res(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); i++) {
            if (cache.find(intervals[i].start) == cache.end()) cache[intervals[i].start] = i;
        }
        for (int i = 0; i < intervals.size(); i++) {
            auto it = cache.lower_bound(intervals[i].end);
            if (it != cache.end()) res[i] = it->second;
        }
        return res;
    }
};
