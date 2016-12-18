//
//  401.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (bitset<10> (i << 6 | j).count() == num) {
                    res.push_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
                }
            }
        }
        return res;
    }
};
