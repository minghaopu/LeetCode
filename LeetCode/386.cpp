
//
//  386.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            res[i-1] = cur;
            if (cur * 10 <= n) cur *= 10;
            else if (cur % 10 != 9 && cur < n) cur++;
            else {
                while ((cur / 10) % 10 == 9) cur /= 10;
                cur = cur / 10 + 1;
            }
        }
        return res;
    }
};
