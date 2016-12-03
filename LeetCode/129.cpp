//
//  129.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper(root, 0, res);
        return res;
    }
    void helper(TreeNode* node, int pre, int& res) {
        if (!node) return;
        pre = pre * 10 + node->val;
        if (!node->left && !node->right) res += pre;
        if (node->left) helper(node->left, pre, res);
        if (node->right) helper(node->right, pre, res);
    }
};
