//
//  284.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool hasPeeked;
    int nextElement;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasPeeked = false;
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!hasPeeked) {
            hasPeeked = true;
            nextElement = Iterator::next();
        }
        return nextElement;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int res = hasPeeked ? nextElement : Iterator::next();
        hasPeeked = false;
        return res;
    }
    
    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }
};
