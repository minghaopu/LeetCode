//
//  98_333.cpp
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
    // 333
    int largestBSTSubtree(TreeNode* root) {
        int minV = INT_MIN, maxV = INT_MAX, res = 0;
        isValidBST(root, minV, maxV, res);
        return res;
    }
    bool isValidBST(TreeNode* node, int &minV, int &maxV, int &res) {
        if (!node) return true;
        int lr = 0, rr = 0;
        int lmin = INT_MIN, lmax = INT_MAX;
        int rmin = INT_MIN, rmax = INT_MAX;
        bool left = isValidBST(node->left, lmin, lmax, lr);
        bool right = isValidBST(node->right, rmin, rmax, rr);
        if (left && right) {
            if ((!node->left || lmax <= node->val) && (!node->right || rmin >= node->val)) {
                res = lr + rr + 1;
                minV = node->left ? lmin : node->val;
                maxV = node->right ? rmax : node->val;
                return true;
            }
        }
        res = max(lr, rr);
        return false;
    }
};
