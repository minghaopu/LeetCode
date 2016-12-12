//
//  366.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
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
class SolutionII {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        while (root) {
            vector<int> tmp;
            helper(root, tmp);
            res.push_back(tmp);
        }
        return res;
    }
    void helper(TreeNode* &node, vector<int>& path) {
        if (!node) return;
        if (!node->left && !node->right) {
            path.push_back(node->val);
            node = NULL;
            return;
        }
        if (node->left) helper(node->left, path);
        if (node->right) helper(node->right, path);
    }
};
// calculate reverse height // root to leaf;
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* &node, vector<vector<int>>& res) {
        if (!node) return -1;
        int left = helper(node->left, res);
        int right = helper(node->right, res);
        int level = max(left, right) + 1;
        if (res.size() <= level) res.resize(level + 1);
        res[level].push_back(node->val);
        return level;
    }
};
