//
//  4. Median of Two Sorted Arrays.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = int(nums1.size());
        int n = int(nums2.size());
        if (n == 0) return double(nums1[(m-1)/2] + nums1[m/2])/2;
        
        int low = 0, high = 2*n;
        while (low <= high) {
            int mid2 = (low + high) / 2;
            int mid1 = m + n - mid2;
            
            double l1 = mid1 == 0 ? INT_MIN : nums1[(mid1-1)/2];
            double l2 = mid2 == 0 ? INT_MIN : nums2[(mid2-1)/2];
            double r1 = mid1 == 2 * m ? INT_MAX : nums1[(mid1)/2];
            double r2 = mid2 == 2 * n ? INT_MAX : nums2[(mid2)/2];
            
            if (l1 > r2) low = mid2 + 1;
            else if (l2 > r1) high = mid2 - 1;
            else return (max(l1, l2) + min(r1, r2)) / 2;
        }
        return -1;
    }
};
