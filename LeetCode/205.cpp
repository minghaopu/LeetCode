

//
//  205.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int tmap[128] = {0};
        int smap[128] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (smap[s[i]] != tmap[t[i]]) return false;
            smap[s[i]] = i+1;
            tmap[t[i]] = i+1;
        }
        return true;
    }
};
