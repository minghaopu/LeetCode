//
//  252_Meeting_Room.cpp
//  LeetCode
//
//  Created by roneil on 16/4/26.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    static bool comparator(Interval i, Interval j){       //This method has to be written in this place.
        return i.start < j.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int sz = intervals.size();
        if (sz < 2) return true;
        sort(intervals.begin(),intervals.end(), comparator);    //O(n) = nlog;
        for (int index = 0; index < intervals.size()-1; index++) {      //O(n) = n;
            if (intervals[index].end > intervals[index+1].start) return false;
        }
        return true;
    };
    
};