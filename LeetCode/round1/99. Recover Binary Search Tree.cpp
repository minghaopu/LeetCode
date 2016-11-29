//
//  99. Recover Binary Search Tree.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/27.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
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
    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* pre;
public:
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        firstNode = NULL;
        secondNode = NULL;
        traverse(root);
        int tmp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tmp;
    }
    void traverse(TreeNode* node) {
        if (node == NULL) return;
        traverse(node->left);
        if (firstNode == NULL && pre->val >= node->val) {
            firstNode = pre;
        }
        if (firstNode != NULL && pre->val >= node->val) {
            secondNode = node;
        }
        pre = node;
        traverse(node->right);
    }
};
