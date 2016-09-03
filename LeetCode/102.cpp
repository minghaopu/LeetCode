//
//  102.cpp
//  LeetCode
//
//  Created by roneil on 9/1/16.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        level(res, root, 0);
        return res;
    }
    void level(vector<vector<int>> &res, TreeNode* root, int l) {
        if (root == NULL) return;
        if(res.size()==l) res.resize(l+1);
        res[l].push_back(root->val);
        level(res, root->left, l+1);
        level(res, root->right, l+1);
    }
};