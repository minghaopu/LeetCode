//
//  270_Closeset_Binary_Search_Tree_Value.cpp
//  LeetCode
//
//  Created by roneil on 16/4/24.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "Header.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double sub = abs(root->val - target), temp;
        TreeNode* cur = root;
        TreeNode* pre = root;
        while (cur != NULL) {
            temp = abs(cur->val - target);
            if (temp<sub) {
                sub = temp;
                pre = cur;
            }
            cur = target > cur->val?cur->right:cur->left;
        }
        return pre->val;
    }
};
