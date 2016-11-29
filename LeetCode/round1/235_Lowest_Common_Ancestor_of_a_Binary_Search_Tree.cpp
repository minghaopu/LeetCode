//
//  235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp
//  LeetCode
//
//  Created by roneil on 7/29/16.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        else if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};