//
//  444.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) return false;
        int len = (int) org.size() + 1;
        int pos[len];
        pos[0] = 0;
        for (int i = 0; i < len - 1; i++) pos[org[i]] = i;
        vector<char> flags(len, 0);
        int toMatch = len - 2;
        for (const auto& v : seqs){
            for (int i = 0; i < v.size(); i++) {
                if (v[i] <= 0 || v[i] >= len) return false;
                if (i == 0) continue;
                int x = v[i-1], y = v[i];
                if (pos[x] >= pos[y]) return false;
                if (flags[x] == 0 && pos[x] + 1 == pos[y]) {
                    flags[x] = 1;
                    toMatch--;
                }
            }
        }
        return toMatch == 0;
    }
};
