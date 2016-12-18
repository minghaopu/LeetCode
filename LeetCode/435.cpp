//
//  435.cpp
//  LeetCode
//
//  Created by neal on 12/14/16.
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        int res = 0, pre = 0;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, Interval& b) {
            return a.start < b.start || (a.start == b.start && a.end < b.end);
        });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[pre].end) {
                res++;
                if (intervals[i].end < intervals[pre].end) pre = i; // remove pre;
            } else pre = i;
        }
        return res;
        
    }
};
