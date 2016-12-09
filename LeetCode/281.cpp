//
//  281.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class ZigzagIterator {
private:
    vector<int> res;
    int index = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int i = 0;
        while (i < v1.size() && i < v2.size()) {
            res.push_back(v1[i]);
            res.push_back(v2[i++]);
        }
        while (i < v1.size()) res.push_back(v1[i++]);
        while (i < v2.size()) res.push_back(v2[i++]);
    }
    
    int next() {
        return res[index++];
    }
    
    bool hasNext() {
        return index != res.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
