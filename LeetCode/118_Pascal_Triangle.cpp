//
//  118_Pascal_Triangle.cpp
//  LeetCode
//
//  Created by roneil on 16/5/14.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++) {
            result[i].resize(i+1);
            for (int j = 0; j <= i; j++) {
                result[i][j] = combinations(i,j);
            }
        }
        return result;
    }
    int combinations(int n, int k) {
        int max = k > n - k ? k : n-k;
        int result = 1;
        for (int i = 1; i <= n - max; i++) {
            result = result * (max + i) / i;
        }
        return result;
    }
};
