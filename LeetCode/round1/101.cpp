//
//  101.cpp
//  LeetCode
//
//  Created by roneil on 8/29/16.
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        else return isSubSymmetric(root->left, root->right);
    }
    bool isSubSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left != NULL && right != NULL && left->val == right->val) return isSubSymmetric(left->left, right->right) && isSubSymmetric(left->right, right->left);
        else return false;
    }
};