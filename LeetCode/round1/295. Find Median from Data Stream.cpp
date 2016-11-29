//
//  295. Find Median from Data Stream.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/27.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if (minHeap.empty() || (num > minHeap.top())) minHeap.push(num);
        else maxHeap.push(num);
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        return minHeap.size() == maxHeap.size() ? 0.5 * (minHeap.top() + maxHeap.top()) : minHeap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
