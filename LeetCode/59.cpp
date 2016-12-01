//
//  59.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i, j;
        int left = 0, right = n-1, up = 0, down = n-1;
        int total = n * n;
        int index = 1;
        vector<vector<int>> res (n, vector<int> (n, 0));
        while (index <= total) {
            for (j = left, i = up; j <= right; j++) res[i][j] = index++;
            if (++up > down) break;
            for (i = up, j = right; i <= down; i++) res[i][j] = index++;
            if (--right < left) break;
            for (j = right, i = down; j >= left; j--) res[i][j] = index++;
            if (--down < up) break;
            for (i = down, j = left; i >= up; i--) res[i][j] = index++;
            if (++left > right) break;
        }
        return res;
    }
};
