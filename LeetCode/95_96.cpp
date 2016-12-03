//
//  95_96.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int numTrees(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j <= n-1; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateSubTrees(1, n);
    }
    vector<TreeNode*> generateSubTrees(int start, int end) {
        if (start > end) return {NULL};
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            // root is i; left is start -> i-1, right is i+1 to-> end;
            vector<TreeNode*> left = generateSubTrees(start, i-1);
            vector<TreeNode*> right = generateSubTrees(i+1, end);
            for (int l = 0; l < left.size(); l++) {
                for (int r = 0; r < right.size(); r++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[l];
                    root->right = right[r];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
