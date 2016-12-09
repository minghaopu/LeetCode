//
//  235_236.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        else if (p->val < root->val && q->val < root->val) return lowestCommonAncestor_BST(root->left, p, q);
        else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor_BST(root->right, p, q);
        else return root;
    }
    TreeNode* lowestCommonAncestor_BT(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor_BT(root->left, p, q);
        TreeNode* right = lowestCommonAncestor_BT(root->right, p, q);
        return !left ? right : (!right ? left : root);
    }
};
