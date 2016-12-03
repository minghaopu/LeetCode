//
//  98.cpp
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
    bool isValidBST(TreeNode* root) {
        return isValidSub(root, NULL, NULL);
    }
    bool isValidSub(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
        return isValidSub(root->left, minNode, root) && isValidSub(root->right, root, maxNode);
    }
};
