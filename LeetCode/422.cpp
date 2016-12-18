//
//  422.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        int m = (int) words.size(), lastSize = (int)words.back().size();
        for (int i = 0; i < m; i++) {
            if (words[i].size() > m || words[i].size() < lastSize) return false;
            for (int j = 0; j < words[i].size(); j++) {
                if (i >= words[j].size()) return false;
                else if (words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};
