//
//  107.cpp
//  LeetCode
//
//  Created by roneil on 9/13/16.
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
    /*
     * iteration with reverse
     */
    vector<vector<int>> levelOrderBottom_it_reverse(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> level;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            if (f != NULL) {
                level.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            } else {
                if (!level.empty()) {
                    q.push(NULL);
                    result.push_back(level);
                    level.clear();
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    /*
     * recursive without reverse
     */
    vector<vector<int>> levelOrderBottom_recursive_no_reverse(TreeNode* root) {
        int height = getTreeHeight(root);
        vector<vector<int>> result(height);
        preOrderTraverse(result, height - 1, root);
        return result;
    }
    void preOrderTraverse(vector<vector<int>> &result, int level, TreeNode* root) {
        if (!root) return;
        result[level].push_back(root->val);
        preOrderTraverse(result, level - 1, root->left);
        preOrderTraverse(result, level - 1, root->right);
    }
    int getTreeHeight(TreeNode* root) {
        if (!root) return 0;
        return max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
    }
};