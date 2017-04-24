//
//  26_80.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/30.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
//    int removeDuplicates(vector<int>& nums) {
//        int count = 0;
//        int n = (int)nums.size();
//        for (int i = 1; i < n; i++) {
//            if (nums[i] == nums[i-1]) count++;
//            else nums[i - count] = nums[i];
//        }
//        nums.resize(n - count);
//        return n - count;
//    }
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1-count]) count++;
            else nums[i-count] = nums[i];
        }
        return nums.size() - count;
    }
    int removeDuplicates_2_Duplicates(vector<int>& nums) {
        int count = 0;
        int n = (int)nums.size();
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i- 2 - count]) count++;
            else nums[i - count] = nums[i];
        }
        nums.resize(n - count);
        return n - count;
    }
    int removeDuplicates_K_Duplicates(vector<int>& nums, int k) {
        int count = 0;
        int n = (int) nums.size();
        for (int i = k; i < n; i++) {
            if (nums[i] == nums[i-k-count]) count++;
            else nums[i-count] = nums[i];
        }
        nums.resize(n - count);
        return n - count;
    }
};
