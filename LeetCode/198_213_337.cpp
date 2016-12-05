//
//  198_213_337.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = (int) nums.size();
        int pre1 = 0, pre2 = 0;
        for (int i = 0; i < len; i++) {
            int tmp = max(pre1, pre2  + nums[i]);
            pre2 = pre1;
            pre1 = tmp;
        }
        return pre1;
    }
    int rob2(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = (int) nums.size();
        if (len == 1) return nums[0];
        int pre1 = 0, pre2 = 0;
        for (int i = 1; i < len; i++) {
            int tmp = max(pre1, pre2 + nums[i]);
            pre2 = pre1;
            pre1 = tmp;
        }
        int rob1 = pre1;
        pre1 = 0;
        pre2 = 0;
        for (int i = 0; i < len-1; i++) {
            int tmp = max(pre1, pre2 + nums[i]);
            pre2 = pre1;
            pre1 = tmp;
        }
        return max(rob1, pre1);
    }
    int rob3(TreeNode* root) {
        vector<int> tmp = tryRob(root);
        return max(tmp[0], tmp[1]);
    }
    vector<int> tryRob(TreeNode* root) {
        if (!root) return {0,0};
        vector<int> left = tryRob(root->left);
        vector<int> right = tryRob(root->right);
        vector<int> res = {0, 0};
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }
};
