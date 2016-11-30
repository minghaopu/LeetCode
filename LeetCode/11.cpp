//
//  11.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int l = 0, r = (int)height.size() - 1;
        int h = 0;
        while (l < r) {
            h = min(height[l], height[r]);
            water = max(water, h * (r - l));
            while (height[l] <= h && l < r) l++;
            while (height[r] <= h && l < r) r--;
        }
        return water;
    }
};
