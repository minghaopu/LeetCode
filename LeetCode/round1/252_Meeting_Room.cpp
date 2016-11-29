//
//  252_Meeting_Room.cpp
//  LeetCode
//
//  Created by roneil on 16/4/26.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
private:

public:
    bool comparator(Interval i, Interval j){       //This method has to be written in this place.
        if (i.start > j.start) {
            if (i.start < j.end) {
                isAll = false;
            }
            return false;
        }
        if (i.start < j.start) {
            if (i.end > j.start) {
                isAll = false;
            }
            return true;
        }
        isAll = false;
        return true;
    }
    bool isAll = true;
    bool canAttendMeetings(vector<Interval>& intervals) {
        int sz = (int)intervals.size();
        if (sz < 2) return true;

        quicksort(intervals, 0, (int)intervals.size()-1);

        return isAll;
    };
    void quicksort(vector<Interval>& intervals, const int left, const int right){
        
        if (left >= right) {
            return;
        }
        int part = partition(intervals, left, right);
        
        quicksort(intervals, left, part - 1);
        quicksort(intervals, part + 1, right);
    }
    int partition(vector<Interval>& intervals, const int left, const int right) {
        Interval x = intervals[right];
        int i = left-1;
        for (int j = left; j< right; j++) {
            if (comparator(intervals[j], x)) {
                i = i+1;
                swapIntervals(intervals, i, j);
            }
        }
        swapIntervals(intervals,i+1, right);
        return i+1;
    }
    void swapIntervals(vector<Interval>& intervals, int i, int j) {
        Interval temp = intervals[i];
        intervals[i] = intervals[j];
        intervals[j] = temp;
    }
};
