//
//  156.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *cur = root, *parent = NULL, *left = NULL, *right = NULL;
        while (cur) {
            left = cur->left;
            cur->left = right;
            right = cur->right;
            cur->right = parent;
            
            parent = cur;
            cur = left;
        }
        return parent;
    }
};
