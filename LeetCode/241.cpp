//
//  241.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input == "") return {};
        vector<int> nums;
        vector<char> ops;
        int num = 0;
        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i])) {
                num = num * 10 + input[i] - '0';
            } else {
                nums.push_back(num);
                num = 0;
                ops.push_back(input[i]);
            }
        }
        nums.push_back(num);
        if (ops.empty()) return nums;
        return helper(nums, ops, 0, (int)nums.size() - 1);
    }
    vector<int> helper(vector<int>& nums, vector<char>& ops, int start, int end) {
        if (end - start == 1) return {compute(nums[start], nums[end], ops[start])};
        vector<int> res, front, back;
        for (int i = start; i < end; i++) {
            if (i == start) {
                back = helper(nums, ops, i + 1, end);
                for (int n : back) res.push_back(compute(nums[start], n, ops[start]));
            } else if (i == end - 1) {
                front = helper(nums, ops, start, i);
                for (int n : front) res.push_back(compute(n, nums[end], ops[end-1]));
            } else {
                front = helper(nums, ops, start, i);
                back = helper(nums, ops, i + 1, end);
                for (int n1 : front) {
                    for (int n2 : back) {
                        res.push_back(compute(n1, n2, ops[i]));
                    }
                }
            }
        }
        return res;
    }
    int compute(int a, int b, char op) {
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else return a * b;
    }
};
