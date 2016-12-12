//
//  341.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    int index;
    vector<int> res;
    void dfs(const vector<NestedInteger> &nestedList) {
        for (NestedInteger item : nestedList) {
            if (item.isInteger()) {
                res.push_back(item.getInteger());
            } else dfs(item.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        dfs(nestedList);
    }
    
    int next() {
        return res[index++];
    }
    
    bool hasNext() {
        return index < res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
