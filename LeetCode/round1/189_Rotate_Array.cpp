//
//  189_Rotate_Array.cpp
//  LeetCode
//
//  Created by roneil on 16/5/10.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if( k == 0 || k ==nums.size())
            return;
        else{
            k = k%(nums.size());
            reverse(nums.begin(),nums.end());
            reverse(nums.begin(),nums.begin() + k);
            reverse(nums.begin()+k,nums.end());
        }
    }
    void rotate2(vector<int>& nums, int k) {
        int l = nums.size();
        if (l < 2) return;
        k = k%nums.size();
        if (k == 0) return;
        int i = 0;
        while (i < k) {
            nums.insert(nums.begin(), nums[l-1]);
            nums.pop_back();
            i++;
        }
    }
};