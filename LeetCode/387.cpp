//
//  387.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};
        int indexes[26] = {-1};
        for (int i = 0; i < s.length(); i++) {
            int j = s[i] - 'a';
            indexes[j] = i;
            map[j]++;
        }
        int index = s.length();
        for (int i = 0; i < 26; i++) {
            if (map[i] == 1) index = min(index, indexes[i]);
        }
        return index == s.length() ? -1 : index;
    }
};
