//
//  100_101.cpp
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL) return q == NULL;
        if (q == NULL) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isOpposite(root->left, root->right);
    }
    bool isOpposite(TreeNode* p, TreeNode* q) {
        if (p == NULL) return q == NULL;
        if (q == NULL) return false;
        return (p->val == q->val) && isOpposite(p->left, q->right) && isOpposite(p->right, q->left);
    }
};
