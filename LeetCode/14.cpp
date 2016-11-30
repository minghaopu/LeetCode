//
//  14.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        int size = (int)strs.size();
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < size; j++) {
                if (i >= strs[j].length() || strs[j][i] != strs[0][i]) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
