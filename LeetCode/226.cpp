//
//  226.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
    TreeNode* invertTree_Iteration(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            if (p) {
                s.push(p->left);
                s.push(p->right);
                swap(p->left, p->right);
            }
        }
        return root;
    }
};
