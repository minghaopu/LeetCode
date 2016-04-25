//
//  258_Add_Digits.cpp
//  LeetCode
//
//  Created by roneil on 16/4/25.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

//https://en.wikipedia.org/wiki/Digital_root

#include "Header.h"

class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};
