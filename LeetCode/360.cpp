//
//  360.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = (int) nums.size(), left = 0, right = n - 1;
        int lv, rv;
        int i = a >= 0 ? n - 1 : 0;
        vector<int> res(n);
        while (left <= right) {
            lv = f(nums[left], a, b, c);
            rv = f(nums[right], a, b, c);
            if (a >= 0) {
                res[i--] = lv >= rv ? lv : rv;
                lv >= rv ? left++ : right--;
            } else {
                res[i++] = lv <= rv ? lv : rv;
                lv <= rv ? left++ : right--;
            }
        }
        return res;
        
    }
    int f(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};
