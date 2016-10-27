//
//  384.cpp
//  LeetCode
//
//  Created by roneil on 10/26/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<int> array;
    int size;
public:
    Solution(vector<int> nums) {
        this->array = nums;
        this->size = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = this->array;
        for (int i = this->size - 1; i > -1; i--) {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
