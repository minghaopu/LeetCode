//
//  99.cpp
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
private:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre;
public:
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        traverse(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    void traverse(TreeNode* node) {
        if (!node) return;
        traverse(node->left);
        if (first == NULL && pre->val >= node->val) first = pre;
        if (first != NULL && pre->val >= node->val) second = node;
        pre = node;
        traverse(node->right);
    }
};
