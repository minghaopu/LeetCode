//
//  390.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : (n/2 + 1 - lastRemaining(n/2)) * 2;
    }
};
