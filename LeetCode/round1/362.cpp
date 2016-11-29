//
//  362.cpp
//  LeetCode
//
//  Created by roneil on 11/17/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class HitCounter {
private:
    int times[300];
    int hits[300];
public:
    /** Initialize your data structure here. */
    HitCounter() {
        memset(times, 0, sizeof(times));
        memset(hits, 0, sizeof(hits));
    }
    
    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp) {
            times[index] = timestamp;
            hits[index] = 1;
        } else {
            hits[index]++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300) total += hits[i];
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
