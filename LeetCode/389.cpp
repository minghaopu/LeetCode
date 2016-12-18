//
//  389.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    char findTheDifference(string s, string t) {
        int tmp = 0;
        for (char c : t) tmp += c;
        for (char c : s) tmp -= c;
        return tmp;
    }
};
