
//
//  222.cpp
//  LeetCode
//
//  Created by roneil on 12/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int num = 1;
        TreeNode *curL = root->left, *curR = root->left;
        while (curR) {
            curL = curL->left;
            curR = curR->right;
            num <<= 1;
        }
        // curR is the right edge of the left sub tree;
        // if (curL == NULL) it means that the left sub tree is full and its size plus root is num;
        // then calculate the right tree;
        // if (curL != NULL) it means that root->left is not full, but root->right must be full; so calculate the root->left;
        return num + (curL ? countNodes(root->left) : countNodes(root->right));
    }
};
