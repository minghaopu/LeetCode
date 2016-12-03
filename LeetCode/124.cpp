//
//  124.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int& res) {
        if (!root) return 0;
        int val = root->val;
        int left = helper(root->left, res), right = helper(root->right, res);
        res = max(val + left + right, res); // cases do not go to upper level;
        return max(0, max(left, right) + val); // cases go to upper level. if smaller than 0, than cut;
    }
};
