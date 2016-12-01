//
//  60.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        string nums = "123456789";
        int fact[n];
        fact[0] = 1;
        k--;
        for (int i = 1; i < n; i++) fact[i] = i * fact[i-1];
        for (int i = n-1; i >= 0; i--) {
            int j = k/fact[i];
            k %= fact[i];
            res += nums[j];
            nums.erase(nums.begin() + j);
        }
        return res;
    }
};
