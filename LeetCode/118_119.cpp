//
//  118_119.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res(1, vector<int> (1, 1));
        for (int i = 1; i < numRows; i++) {
            res.push_back(res.back());
            res.back().push_back(1);
            for (int j = 1; j < res.back().size() - 1; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex+1, 1);
        for (int i = 1; i <= (rowIndex + 1) / 2; i++) {
            r[i] = r[rowIndex - i] = int((long)r[i-1] * (long)(rowIndex - i + 1) / i);
        }
        return r;
    }
};
