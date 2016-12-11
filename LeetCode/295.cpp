//
//  295.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return double(minHeap.top() + maxHeap.top()) / 2;
        }
        else return maxHeap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
