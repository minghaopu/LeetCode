//
//  335.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int len = (int) x.size();
        if (len < 3) return false;
        for (int i = 3; i < len; i++) {
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            if (i > 3 && (x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2])) return true;
            if (i > 4 && (x[i-1] + x[i-5] >= x[i-3] && x[i-1] <= x[i-3] && x[i] + x[i-4] >= x[i-2] && x[i-2] >= x[i-4])) return true;
        }
        return false;
    }
};
