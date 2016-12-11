//
//  300.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
            // for (int n : res) cout<<n<<":";
            // cout<<endl;
        }
        return (int)res.size();
    }
};
