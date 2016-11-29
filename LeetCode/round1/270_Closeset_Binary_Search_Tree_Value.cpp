//
//  270_Closeset_Binary_Search_Tree_Value.cpp
//  LeetCode
//
//  Created by roneil on 16/4/24.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "Header.h"


class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double min = root->val;
        while (root != NULL) {
            min = abs(root->val - target)<abs(min - target)?root->val:min;
            root = target > root->val?root->right:root->left;
        }
        return min;
    }
};
