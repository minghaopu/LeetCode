//
//  77.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp(k, 0);
        int i = 0;
        while (i >= 0) {
            tmp[i]++;
            if (tmp[i] > n) i--;
            else if (i == k-1) res.push_back(tmp);
            else {
                i++;
                tmp[i] = tmp[i-1];
            }
            for (int n : tmp) cout<<n<<":";
            cout<<endl;
        }
        return res;
    }
};
//output
//1:1
//1:2
//1:3
//1:4
//1:5
//2:2
//2:3
//2:4
//2:5
//3:3
//3:4
//3:5
//4:4
//4:5
//5:5
