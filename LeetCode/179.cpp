//
//  179.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "";
        sort(nums.begin(), nums.end(), [](const int a, const int b) {
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        string res;
        for (int n : nums) res += to_string(n);
        int i = 0;
        while (i < res.length() - 1 && res[i] == '0') i++;
        return res.substr(i);
    }
};
