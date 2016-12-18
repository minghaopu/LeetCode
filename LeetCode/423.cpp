//
//  423.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string originalDigits(string s) {
        int map[26];
        memset(map, 0, sizeof(map));
        for (char c : s) map[c - 'a']++;
        int count[10];
        count[0] = map[25];
        count[2] = map[22];
        count[4] = map[20];
        count[6] = map[23];
        count[8] = map[6];
        map[14] -= (count[2] + count[4]+ count[0]) ;
        count[1] = map[14];
        map[7] -= count[8];
        count[3] = map[7];
        map[5] -= count[4];
        count[5] = map[5];
        map[18] -= map[23];
        count[7] = map[18];
        map[8] -= (count[5] + count[6] + count[8]);
        count[9] = map[8];
        string res ="";
        for (int i = 0; i <= 9; i++) {
            if (count[i] != 0) res.append(count[i], char('0' + i));
        }
        return res;
    }
};
