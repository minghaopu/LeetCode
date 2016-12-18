//
//  469.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = (int)points.size();
        if(n <= 3) return true;
        points.push_back(points[0]);
        points.push_back(points[1]);
        long cur = 0, pre = 0;
        for(int i = 2; i < n+2; ++i) {
            int x1 = points[i-1][0] - points[i-2][0];
            int y1 = points[i-1][1] - points[i-2][1];
            int x2 = points[i][0] - points[i-2][0];
            int y2 = points[i][1] - points[i-2][1];
            cur = x1*y2-x2*y1;
            if (cur != 0) {
                if(pre*cur < 0) return false;
                else pre = cur;
            }
        }
        points.pop_back();
        points.pop_back();
        return true;
    }
};
