//
//  315.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = (int) nums.size();
        vector<int> res(len), sorted;
        for (int i = len - 1; i > -1; i--) {
            res[i] = binarySearch(sorted, nums[i]);
        }
        return res;
    }
    int binarySearch(vector<int>& sorted, int target) {
        if (sorted.empty()) {
            sorted.push_back(target);
            return 0;
        }
        int l = 0, r = (int)sorted.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (sorted[mid] < target) l = mid + 1;
            else r = mid;
        }
        sorted.insert(sorted.begin() + l, target);
        return l;
    }
};
