//
//  153_154.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size()-1, mid;
        while (left < right) {
            mid = (right + left) / 2;
            if (nums[mid] < nums[right]) right = mid;
            else left = mid + 1;
        }
        return nums[left];
    }
    int findMin_Duplicate_method1(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1, mid;
        while (left < right) {
            while (left < right - 1 && nums[left] == nums[left + 1]) left++;
            while (left < right - 1 && nums[right] == nums[right - 1]) right--;
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) right = mid;
            else left = mid + 1;
        }
        return nums[left];
    }
    int findMin_Duplicate_method2(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) right = mid;
            else if (nums[mid] > nums[right]) left = mid + 1;
            else right--;
        }
        return nums[left];
    }
};
