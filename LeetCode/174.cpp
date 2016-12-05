//
//  174.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 0;
        int m = (int) dungeon.size(), n = (int) dungeon[0].size();
        vector<vector<int>> hp(m+1, vector<int> (n+1, INT_MAX));
        hp[m][n-1] = 1;
        hp[m-1][n] = 1;
        for (int i = m-1; i>-1; i--) {
            for (int j = n-1; j>-1; j--) {
                int need = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};
