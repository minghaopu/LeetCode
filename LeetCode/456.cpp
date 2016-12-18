//
//  456.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int second = INT_MIN;
        for (int i = (int)nums.size() - 1; i > -1; i--) {
            if (nums[i] < second) return true;
            else {
                while (!s.empty() && nums[i] > s.top()) {
                    second = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
    
};
