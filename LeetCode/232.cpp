//
//  232.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class MyQueue {
private:
    stack<int> sin, sout;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sin.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        sout.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (sout.empty()) {
            while (!sin.empty()) {
                sout.push(sin.top());
                sin.pop();
            }
        }
        return sout.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sin.empty() && sout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
