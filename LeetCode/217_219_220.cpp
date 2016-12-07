//
//  217_219_220.cpp
//  LeetCode
//
//  Created by roneil on 12/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Queue {
private:
    stack<int> sin, sout;
public:
    // Push element x to the back of queue.
    void push(int x) {
        sin.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        sout.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if (sout.empty()) {
            while (!sin.empty()) {
                sout.push(sin.top());
                sin.pop();
            }
        }
        return sout.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return sin.empty() && sout.empty();
    }
};
