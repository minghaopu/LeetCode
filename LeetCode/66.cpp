//
//  66.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] > 9 ? 1 : 0;
            digits[i] %= 10;
        }
        if (carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};
