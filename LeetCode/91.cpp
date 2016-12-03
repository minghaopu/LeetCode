//
//  91.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int numDecodings(string s) {
        if (s == "" || s[0] == '0') return 0;
        int dp1 = 1, dp2 = 1; // dp1 = i-1, dp2 = i-2;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') dp1 = 0;
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <'7')) {
                dp1 = dp1 + dp2; // new dp = dp1 + dp2; dp1 = new dp;
                dp2 = dp1 - dp2; // dp2 = dp1 - dp2 = new dp - dp2 = old dp1 + dp2 - dp2 = old dp1;
            } else {
                dp2 = dp1;
            }
        }
        return dp1;
    }
};
