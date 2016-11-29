//
//  111.cpp
//  LeetCode
//
//  Created by roneil on 9/1/16.
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left != NULL && root->right == NULL) return 1 + minDepth(root->left);
        if (root->right != NULL && root->left == NULL) return 1 + minDepth(root->right);
        else return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};