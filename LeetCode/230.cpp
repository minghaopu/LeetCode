//
//  230.cpp
//  LeetCode
//
//  Created by roneil on 11/7/16.
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
private:
    int count;
    int helper(TreeNode* root) {
        int res = -1;
        if (root->left != NULL) res = helper(root->left);
        if (res != -1) return res;
        count--;
        if (count == 0) {
            return root->val;
        }
        if (root->right != NULL) res = helper(root->right);
        return res;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        return helper(root);
    }
    
};
