//
//  258_Add_Digits.cpp
//  LeetCode
//
//  Created by roneil on 16/4/25.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    Solution() {};
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};
