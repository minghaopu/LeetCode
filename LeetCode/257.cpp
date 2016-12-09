//
//  257.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(res, "", root);
        return res;
    }
    void helper(vector<string>& res, string path, TreeNode* node) {
        if (node == NULL) return;
        
        if (path == "") path += to_string(node->val);
        else path += "->" + to_string(node->val);
        
        if (!node->left && !node->right) res.push_back(path);
        if (node->left) helper(res, path, node->left);
        if (node->right) helper(res, path, node->right);
    }
};
