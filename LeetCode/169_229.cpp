//
//  169_229.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                n = nums[i];
                count++;
            } else if (n == nums[i]) count++;
            else count--;
        }
        return n;
    }
    vector<int> majorityElement_II(vector<int>& nums) {
        int major1 = 0, major2 = 0, count1 = 0, count2 = 0;
        for (int n : nums) {
            if (major1 == n) count1++;
            else if (major2 == n) count2++;
            else if (count1 == 0) {
                major1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                major2 = n;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int n : nums) {
            if (major1 == n) count1++;
            else if (major2 == n) count2++;
        }
        vector<int> res;
        if (count1 > nums.size() / 3) res.push_back(major1);
        if (count2 > nums.size() / 3) res.push_back(major2);
        return res;
        // unordered_map<int, int> hash;
        // for (int n : nums) hash[n]++;
        // vector<int> res;
        // int t = (int) nums.size() / 3;
        // for (auto it = hash.begin(); it != hash.end(); it++) {
        //     if (it->second > t) res.push_back(it->first);
        // }
        // return res;
    }
};
