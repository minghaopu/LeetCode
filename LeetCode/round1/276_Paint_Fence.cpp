//
//  276_Paint_Fence.cpp
//  LeetCode
//
//  Created by roneil on 16/4/20.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
private:
    int n;
    int k;
public:
    Solution(int num, int color) {
        n = num;
        k = color;
    }
//    int numWays() {
//        if (n==0 || k==0) return 0;
//        int num[] = {k, k*k, 0};
//        if (n<3) {
//            return num[n-1];
//        };
//        for (int i = 2; i<n; i++) {
//            num[2] = (k-1) * (num[0] + num[1]);
//            num[0] = num[1];
//            num[1] = num[2];
//        }
//        return num[2];
//    }
    int numWays() {
        if (n==0 || k==0) return 0;
        if (n == 1) {
            return k;
        };
        int diff[n];   // i-1 i-2 dif
        int same[n];   // i-1 i-2 same
        diff[0] = k;
        same[0] = 0;
        for (int i = 1; i<n; i++) {
            same[i] = diff[i-1];
            diff[i] = (k-1) * (same[i-1]+diff[i-1]);
        }
        return diff[n-1]+same[n-1];
    }

};
