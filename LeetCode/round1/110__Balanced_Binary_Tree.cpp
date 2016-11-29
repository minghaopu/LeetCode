//
//  110__Balanced_Binary_Tree.cpp
//  LeetCode
//
//  Created by roneil on 16/5/14.
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
public:
    bool isBalanced(TreeNode* root) {
        return testBalance(root) == -1 ? false : true;
    }
    int testBalance(TreeNode* root) {
        if (root == NULL) return 0;
        int left = testBalance(root->left);
        if (left == -1) return -1;
        int right = testBalance(root->right);
        if (right == -1) return -1;
        int dif = left - right;
        if (dif > 1 || dif < -1) return -1;
        else return (dif > 0 ? left : right)+1;
    }
};