//
//  314.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int, vector<int>> cache;
        queue<pair<int, TreeNode*>> q;
        TreeNode* node = NULL;
        q.push({0, root});
        int size, val;
        while (!q.empty()) {
            size = (int)q.size();
            while (size--) {
                auto p = q.front();
                val = p.first;
                node = p.second;
                q.pop();
                cache[val].push_back(node->val);
                if (node->left) q.push({val - 1, node->left});
                if (node->right) q.push({val + 1, node->right});
            }
        }
        vector<vector<int>> res;
        for (auto item : cache) {
            res.push_back(item.second);
        }
        return res;
    }
};
