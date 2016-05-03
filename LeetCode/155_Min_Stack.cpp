//
//  155_Min_Stack.cpp
//  LeetCode
//
//  Created by roneil on 16/5/2.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class MinStack {
private:
public:
    vector<int> stack;
    int min;
    /** initialize your data structure here. */
    
    void push(int x) {
        if (stack.empty()) min = x;
        stack.push_back(x-min);
        min = min < x ? min: x;
    }
    
    void pop() {
        if (stack.empty()) return;
        if (stack.back() < 0) min = min - stack.back();
        stack.pop_back();
    }
    
    int top() {
        if (stack.empty()) return NULL;
        return stack.back() > 0 ? min + stack.back() : min;
    }
    
    int getMin() {
        if (stack.empty()) return NULL;
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */