//
//  270_272.cpp
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
    int closestValue(TreeNode* root, double target) {
        
        int closet = root->val;
        helper(root, target, closet);
        return closet;
    }
    void helper(TreeNode* node, double target, int& closet) {
        if (!node) return;
        if (abs(target - (double)closet) > abs(target - (double)node->val)) {
            closet = node->val;
        }
        if (target > node->val) helper(node->right, target, closet);
        else if (target < node->val) helper(node->left, target, closet);
        else return;
    }
    int closestValue_method2(TreeNode* root, double target) {
        double closet = root->val;
        while (root) {
            if (target == root->val) return root->val;
            closet = abs(target - root->val) < abs(target - closet) ? root->val : closet;
            root = target > root->val ? root->right : root->left;
        }
        return closet;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> q;
        helper(root, target, k, q);
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    void helper(TreeNode* node,double target, int k, priority_queue<pair<double, int>>& q) {
        if (!node) return;
        q.push({fabs(target - (double)node->val), node->val});
        if (q.size() > k) q.pop();
        helper(node->left, target, k, q);
        helper(node->right, target, k, q);
    }
};
