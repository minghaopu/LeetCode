//
//  412.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            if (i % 3 != 2 && i % 5 != 4) res[i] = to_string(i+1);
            if (i % 3 == 2) res[i] = "Fizz";
            if (i % 5 == 4) res[i] += "Buzz";
        }
        return res;
    }
};
