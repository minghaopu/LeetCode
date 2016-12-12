//
//  346.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class MovingAverage {
    queue<int> q;
    int count;
    int maxSize;
    int sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        count = 0;
        maxSize = size;
    }
    
    double next(int val) {
        if (count == maxSize) {
            sum -= q.front();
            q.pop();
            count--;
        }
        count++;
        sum += val;
        q.push(val);
        return (double) sum / count;
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
