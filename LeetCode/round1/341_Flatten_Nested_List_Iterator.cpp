//
//  341_Flatten_Nested_List_Iterator.cpp
//  LeetCode
//
//  Created by roneil on 11/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class NestedIterator {
private:
    stack<NestedInteger> nodes;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i > -1; i--) {
            nodes.push(nestedList[i]);
        }
    }
    
    int next() {
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }
    
    bool hasNext() {
        while(!nodes.empty()) {
            NestedInteger top = nodes.top();
            if (top.isInteger()) {
                return true;
            }
            nodes.pop();
            vector<NestedInteger> tmp = top.getList();
            for (int i = tmp.size()-1; i > -1; i--) {
                nodes.push(tmp[i]);
            }
        }
        return false;
    }
};
