//
//  168.cpp
//  LeetCode
//
//  Created by roneil on 8/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    string convertToTitle(int n) {
        char nums[26] = {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
            'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T', 'U',
            'V', 'W', 'X', 'Y'};
        string result = "";
        while (n > 0) {
            result = char(nums[n % 26]) + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};