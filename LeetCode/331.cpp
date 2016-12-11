//
//  331.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string token;
        int diff = 1; // root outdegree - indegree
        while (getline(ss, token, ',')) {
            diff--;
            if (diff < 0) return false;
            else if (token != "#") diff += 2;
        }
        return diff == 0;
    }
};
