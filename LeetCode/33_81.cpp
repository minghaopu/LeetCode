//
//  33_81.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = (int)nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if ((nums[left] <= nums[mid] && (nums[left] > target || nums[mid] < target)) || (nums[left] > nums[mid] && nums[mid] < target && target <= nums[right])) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    bool search_duplicate(vector<int>& nums, int target) {
        int n = (int) nums.size();
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            while (low <= high && nums[low] == nums[low+1]) low++;
            while (low <= high && nums[high] == nums[high-1]) high--;
            mid = (low + high) / 2;
            if (nums[mid] == target) return true;
            else if ((nums[low] <= nums[mid] && (nums[low] > target || target > nums[mid])) || (nums[low] > nums[mid] && nums[mid] < target && target <= nums[high])) low = mid + 1;
            else high = mid - 1;
            
        }
        return false;
    }
};
