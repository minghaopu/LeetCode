//
//  454.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void fillMap(vector<int>& A, vector<int>& B, unordered_map<int, int>& sums) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) sums[A[i] + B[j]]++;
        }
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m1, m2;
        fillMap(A, B, m1);
        fillMap(C, D, m2);
        int res = 0;
        for (auto it = m1.begin(); it != m1.end(); it++) {
            auto it2 = m2.find(-it->first);
            if (it2 != m2.end()) res += it->second * it2->second;
        }
        return res;
    }
};
