//
//  387.cpp
//  LeetCode
//
//  Created by roneil on 9/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> m (26, 0);
        for (int i = 0; i < s.length(); i++) {
            m[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};