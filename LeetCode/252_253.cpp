//
//  252_253.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b) {
            return a.start < b.start || (a.start == b.start && a.end < b.end);
        });
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i].end > intervals[i+1].start) return false;
        }
        return true;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
         if (intervals.empty()) return 0;
         int len = (int) intervals.size();
         vector<int> start(len, 0);
         vector<int> end(len, 0);
         for (int i = 0; i < len; i++) {
             start[i] = intervals[i].start;
             end[i] = intervals[i].end;
         }
         sort(start.begin(), start.end());
         sort(end.begin(), end.end());
         int res = 0;
         for (int i = 0, j = 0; i < len; i++) {
             if (start[i] < end[j]) res++;
             else j++;
         }
         return res;
    }
    int minMeetingRooms_slow(vector<Interval>& intervals) {
        map<int, int> hash;
        for (Interval i : intervals) {
            hash[i.start]++;
            hash[i.end]--;
        }
        int count = 0, maxCount = 0;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            count += it->second;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
