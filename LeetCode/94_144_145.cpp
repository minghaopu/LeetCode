//
//  94_144_145.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

// tree
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            res.push_back(top->val);
            if (top->right) st.push(top->right);
            if (top->left) st.push(top->left);
        }
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* top = st.top();
            if (top->left) {
                st.push(top->left);
                top->left = NULL;
            } else {
                res.push_back(top->val);
                st.pop();
                if (top->right) st.push(top->right);
            }
        }
        return res;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root, *last = NULL, *top = NULL;
        while(cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                top = st.top();
                if (top->right && top->right != last) cur = top->right;
                else {
                    st.pop();
                    res.push_back(top->val);
                    last = top;
                }
            }
        }
        return res;
    }
};
