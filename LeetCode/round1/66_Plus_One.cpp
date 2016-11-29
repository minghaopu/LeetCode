//
//  66_Plus_One.cpp
//  LeetCode
//
//  Created by roneil on 16/5/4.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool isCarried = false;
        for (int index = digits.size() - 1; index > -1; index--) {
            int t = digits[index];
            if (index == digits.size() - 1 || isCarried) {
                t++;
                if (t == 10) {
                    digits[index] = 0;
                    isCarried = true;
                }else{
                    digits[index] = t;
                    isCarried = false;
                }
            }
            
            if (index != digits.size() - 1 && !isCarried) {
                return digits;
            }
        }
        if (isCarried) digits.insert(digits.begin(), 1);
        return digits;
    }
};