//
//  112_113.cpp
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
    // path sum I
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->val == sum && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
    // path sum II
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> path;
        stack<TreeNode*> st;
        int total = 0;
        TreeNode *cur = root;
        TreeNode *last = NULL, *top;
        while(cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                path.push_back(cur->val);
                total += cur->val;
                cur = cur->left;
            } else {
                top = st.top();
                if (!top->left && !top->right && total == sum) res.push_back(path);
                if (top->right && top->right != last) cur = top->right;
                else {
                    st.pop();
                    path.pop_back();
                    total -= top->val;
                    last = top;
                }
            }
        }
        return res;
    }
    vector<vector<int>> pathSum_DFS(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, root, sum);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int> path, TreeNode* root, int sum) {
        if (!root) return;
        if (root->val == sum && !root->left && !root->right) {
            path.push_back(sum);
            res.push_back(path);
            return;
        }
        int rest = sum - root->val;
        path.push_back(root->val);
        dfs(res, path, root->left, rest);
        dfs(res, path, root->right, rest);
    }
    // path sum III
    int pathSumIII(TreeNode* root, int sum) {
        if (!root) return 0;
        return helper(root, 0, sum) + pathSumIII(root->left, sum) + pathSumIII(root->right, sum);
    }
    int helper(TreeNode* node, int pre, int sum) {
        if (!node) return 0;
        int cur = node->val + pre;
        return (cur == sum ? 1 : 0) + helper(node->left, cur, sum) + helper(node->right, cur, sum);
    }
};
