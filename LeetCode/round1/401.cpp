//
//  401.cpp
//  LeetCode
//
//  Created by roneil on 11/17/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h";
vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 60; j++) {
            if (bitset<10> (i << 6 | j).count() == num) {
                res.emplace_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
            }
        }
    }
    return res;
}
