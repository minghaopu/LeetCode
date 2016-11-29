//
//  281.cpp
//  LeetCode
//
//  Created by roneil on 11/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class ZigzagIterator {
    vector<int> zig;
    int index;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        index = 0;
        int i = 0;
        while (i < max(int(v1.size()), int(v2.size()))) {
            if (i < v1.size()) zig.push_back(v1[i]);
            if (i < v2.size()) zig.push_back(v2[i]);
            i++;
        }
    }
    
    int next() {
        return zig[index++];
    }
    
    bool hasNext() {
        return index < zig.size();
    }
};
class ZigzagIterator_iterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
public:
    ZigzagIterator_iterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) Q.push({v1.begin(), v1.end()});
        if (!v2.empty()) Q.push({v2.begin(), v2.end()});
    }
    
    int next() {
        auto front = Q.front();
        int result = *front.first;
        Q.pop();
        if (++front.first != front.second) Q.push(front);
        return result;
    }
    
    bool hasNext() {
        return !Q.empty();
    }
};
