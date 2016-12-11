
//
//  298.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
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
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        return max(helper(root->left, 1, root->val), helper(root->right, 1, root->val));
    }
    int helper(TreeNode* node, int len, int parentVal) {
        if (!node) return len;
        if (node->val == parentVal + 1) len++;
        else len = 1;
        return max(max(helper(node->left, len, node->val), helper(node->right, len, node->val)), len);
    }
};
