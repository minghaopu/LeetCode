//
//  258.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
