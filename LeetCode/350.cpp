//
//  350.cpp
//  LeetCode
//
//  Created by roneil on 9/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
//   not use hash map
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return result;
    }
//    use hash map
    vector<int> intersect_hash(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (--m[nums2[i]] >= 0) {
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};