//
//  404.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int total = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right) total += root->left->val;
            else total += sumOfLeftLeaves(root->left);
        }
        if (root->right) total += sumOfLeftLeaves(root->right);
        return total;
        
    }
};
