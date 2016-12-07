


//
//  230.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
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
    int helper(TreeNode *node, int& count) {
        int res = -1;
        if (node->left) res = helper(node->left, count);
        if (res != -1) return res;
        count--;
        if (count == 0) return node->val;
        if (node->right) res = helper(node->right, count);
        return res;
    }
public:
    int kthSmallest_Recur(TreeNode* root, int k) {
        return helper(root, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = root;
        
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (--k == 0) return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};
