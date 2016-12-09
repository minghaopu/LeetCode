//
//  250.cpp
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
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        helper(root, count);
        return count;
    }
    bool helper(TreeNode* node, int& count) {
        if (!node) return true;
        bool left = helper(node->left, count);
        bool right = helper(node->right, count);
        if (left && right
            && (!node->left || node->val == node->left->val)
            && (!node->right || node->val == node->right->val)
            ) {
            count++;
            return true;
        }
        return false;
    }
};
