//
//  455.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.empty() || s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] > s[j]) j++;
            else {
                i++;
                j++;
            }
        }
        return i;
    }
};
