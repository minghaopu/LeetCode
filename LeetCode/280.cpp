//
//  280.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (((i & 1) && nums[i] < nums[i-1]) || (!(i & 1) && nums[i] > nums[i-1])) swap(nums[i], nums[i-1]);
        }
    }
    void wiggleSort_II(vector<int>& nums) {
        int n = (int) nums.size();
        int mid = n/2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        partition(nums, nums[mid]);
        int largeStart = n - 1;
        int smallStart = (n % 2) ? mid : (mid - 1);
        vector<int> res(n);
        for (int i = 0; i < n; i+=2) res[i] = nums[smallStart--];
        for (int i = 1; i < n; i+=2) res[i] = nums[largeStart--];
        nums = res;
    }
    void partition(vector<int>& nums, int val) {
        int i = 0, j = 0;
        int n = (int) nums.size() - 1;
        while (j <= n) {
            if (nums[j] < val) swap(nums[i++], nums[j++]);
            else if (nums[j] > val) swap(nums[j], nums[n--]);
            else j++;
        }
    }
};
