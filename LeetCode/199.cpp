
//
//  199.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> Q {root};
        vector<int> res;
        int index = 0, size;
        while (index < Q.size()) {
            size = (int)Q.size();
            while (index < size) {
                TreeNode *node = Q[index++];
                if (index == size) res.push_back(node->val);
                if (node->left) Q.push_back(node->left);
                if (node->right) Q.push_back(node->right);
            }
        }
        return res;
    }
};
