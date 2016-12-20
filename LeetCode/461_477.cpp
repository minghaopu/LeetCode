//
//  461_477.cpp
//  LeetCode
//
//  Created by neal on 12/19/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y, count = 0;
        while (tmp != 0) {
            if (tmp & 1) count++;
            tmp >>= 1;
        }
        return count;
    }
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = (int)nums.size();
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int n : nums) count += (n >> i) & 1;
            total += count * (n - count);
        }
        return total;
    }
};
