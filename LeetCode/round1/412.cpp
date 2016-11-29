//
//  412.cpp
//  LeetCode
//
//  Created by roneil on 10/26/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
vector<string> fizzBuzz(int n) {
    int val;
    string s;
    vector<string> res;
    res.resize(n);
    for (int i = 0; i < n; i++) {
        val = i + 1;
        if (val % 15 == 0) s = "FizzBuzz";
        else if (val % 3 == 0) s = "Fizz";
        else if (val % 5 == 0) s = "Buzz";
        else s = to_string(val);
        res[i] = s;
    }
    return res;
}
