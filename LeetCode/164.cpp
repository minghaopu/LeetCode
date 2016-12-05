//
//  164.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int minN = INT_MAX, maxN = INT_MIN, len = (int) nums.size();
        for (int n : nums) {
            if (minN > n) minN = n;
            if (maxN < n) maxN = n;
        }
        int bucketLength = (maxN - minN) / len + 1;
        int bucketNum = (maxN - minN) / bucketLength + 1;
        vector<vector<int>> bucket(bucketNum, vector<int> {INT_MAX, INT_MIN});
        for (int n : nums) {
            int pos = (n - minN) / bucketLength;
            if (n < bucket[pos][0]) bucket[pos][0] = n;
            if (n > bucket[pos][1]) bucket[pos][1] = n;
        }
        int gap = 0, pre = 0;
        for (int i = 1; i < bucketNum; i++) {
            if (bucket[i][0] == INT_MAX) continue;
            gap = max(bucket[i][0] - bucket[pre][1], gap);
            pre = i;
        }
        return gap;
    }
};
