//
//  57. Insert Interval.cpp
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) return {newInterval};
        auto comp = [](const Interval a, const Interval b) {return a.start < b.start || (a.start == b.start && a.end < b.end);};
        sort(intervals.begin(), intervals.end(), comp);
        int n = (int) intervals.size();
        int i = 0;
        while (i < n && intervals[i].end < newInterval.start) i++;
        
        if (i == n) intervals.insert(intervals.begin() + i, newInterval);
        else {
            int j = i;
            int start = min(newInterval.start, intervals[i].start);
            while (j < n && newInterval.end >= intervals[j].start) j++;
            int end = max(newInterval.end, intervals[j-1].end);
            intervals.erase(intervals.begin() + i, intervals.begin() + j);
            intervals.insert(intervals.begin() + i, Interval(start, end));
        }
        
        return intervals;
    }
};
