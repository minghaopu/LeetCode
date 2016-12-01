//
//  42.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int ml = 0, mr = 0;
        int water = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= ml) ml = height[left];
                else water += ml - height[left];
                left++;
            } else {
                if (height[right] >= mr) mr = height[right];
                else water += mr - height[right];
                right--;
            }
        }
        return water;
    }
};
