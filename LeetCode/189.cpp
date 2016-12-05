//
//  189.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = (int) nums.size();
        k %= len;
        for (int i = 0; i < len; i++) nums.push_back(nums[i]);
        nums.erase(nums.begin(), nums.begin() + len - k);
        nums.erase(nums.begin() + len, nums.end());
    }
    void rotate2(vector<int>& nums, int k) {
        if( k == 0 || k ==nums.size())
            return;
        else{
            k = k%(nums.size());
            reverse(nums.begin(),nums.end());
            reverse(nums.begin(),nums.begin() + k);
            reverse(nums.begin()+k,nums.end());
        }
    }
    void rotate3(vector<int>& nums, int k) {
        int l = (int)nums.size();
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
