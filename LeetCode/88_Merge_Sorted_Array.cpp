//
//  88_Merge_Sorted_Array.cpp
//  LeetCode
//
//  Created by roneil on 16/5/11.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1, j = n - 1, k = m + n - 1; j >= 0; k--) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i--];
            }else {
                nums1[k] = nums2[j--];
            }
        }
    }
};
