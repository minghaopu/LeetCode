//
//  102_103.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//
// BFS
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
        if (!root) return {};
        vector<vector<int>> res;
        int size = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* front;
        while (!qu.empty()) {
            size = (int)qu.size();
            vector<int> tmp(size);
            for (int i = 0; i < size; i++) {
                front = qu.front();
                qu.pop();
                tmp[i] = front->val;
                if (front->left) qu.push(front->left);
                if (front->right) qu.push(front->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> qu;
        int count = 0;
        int size;
        qu.push(root);
        TreeNode* front;
        while (!qu.empty()) {
            size = (int)qu.size();
            vector<int> tmp(size);
            int index = count % 2 == 1 ? size - 1 : 0;
            int incre = count % 2 == 1 ? -1 : 1;
            while (index > -1 && index < size) {
                front = qu.front();
                qu.pop();
                tmp[index] = front->val;
                if (front->left) qu.push(front->left);
                if (front->right) qu.push(front->right);
                index += incre;
            }
            count++;
            res.push_back(tmp);
        }
        return res;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        int size;
        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* front;
        while (!qu.empty()) {
            size = (int)qu.size();
            vector<int> tmp(size);
            for (int i = 0; i < size; i++) {
                front = qu.front();
                tmp[i] = front->val;
                qu.pop();
                if (front->left) qu.push(front->left);
                if (front->right) qu.push(front->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
