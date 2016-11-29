//
//  349.cpp
//  LeetCode
//
//  Created by roneil on 9/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                if (r.empty() || r.back() != nums1[i]) {
                    r.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return r;
    }
};