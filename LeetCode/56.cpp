//
//  56.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        auto comp = [](const Interval a, const Interval b) {return a.start < b.start || (a.start == b.start && a.end < b.end);};
        sort(intervals.begin(), intervals.end(), comp);
        int start = intervals[0].start;
        int end = intervals[0].end;
        vector<Interval> res;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > end) {
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            } else if (intervals[i].end > end) end = intervals[i].end;
        }
        res.push_back(Interval(start, end));
        return res;
    }
};
