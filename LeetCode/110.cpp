//
//  110.cpp
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
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int left = getHeight(node->left);
        if (left == -1) return - 1;
        int right = getHeight(node->right);
        if (right == -1) return -1;
        int dif = left - right;
        if (dif > 1 || dif < -1) return -1;
        int height = (left > right ? left : right) + 1;
        return height;
    }
};
