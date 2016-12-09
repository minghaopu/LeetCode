//
//  163.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long pre = lower-1, cur = 0;
        for (int i = 0; i <= nums.size(); i++) {
            cur = i == nums.size() ? upper + 1 : nums[i];
            if (cur - pre >= 2) res.push_back(getRange((int)pre+1, (int)cur-1));
            pre = cur;
        }
        return res;
    }
    string getRange(int start, int end) {
        return to_string(start) + (start == end ? "" : "->" + to_string(end));
    }
};
