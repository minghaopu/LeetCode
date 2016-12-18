//
//  448.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            int m = abs(nums[i])-1;// the actuall index of the val;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
            for (int n : nums) cout<<n<<',';
        }
        vector<int> res;
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};
