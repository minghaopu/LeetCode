//
//  451.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string frequencySort(string s) {
        int map[128] = {0};
        vector<string> bucket(s.size() + 1, "");
        string res;
        for (char c : s) map[c]++;
        for (int i = 0; i < 128; i++) {
            int f = map[i];
            if (f != 0) bucket[f].append(f, char(i));
        }
        for (int i = (int) s.size(); i > 0; i--) {
            if (bucket[i] != "") res += bucket[i];
        }
        return res;
    }
};
