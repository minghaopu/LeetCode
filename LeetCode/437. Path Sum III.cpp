//
//  437. Path Sum III.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int helper(TreeNode* node, int pre, int sum) {
        if (node == NULL) return 0;
        int cur = node->val + pre;
        return (cur == sum ? 1 : 0) + helper(node->left, cur, sum) + helper(node->right, cur, sum);
    }
};
