//
//  277.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n <= 1) return n;
        int candidate = 0;
        for (int i = 0; i < n; i++) {
            if (!knows(i, candidate)) candidate = i;
        }
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) return - 1;
        }
        return candidate;
    }
};
