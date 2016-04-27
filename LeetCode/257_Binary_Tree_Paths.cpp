//
//  257_Binary_Tree_Paths.cpp
//  LeetCode
//
//  Created by roneil on 16/4/25.
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
    Solution () {};
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        findPath(root, paths, "");
        return paths;
    }
    void findPath(TreeNode* root, vector<string> &paths, string path) {
        if (root == NULL) {
            return;
        }else{
            path += to_string(root->val);
            if (root->left==NULL&&root->right==NULL) {
                paths.push_back(path);
            }else{
                path += "->";
                findPath(root->left, paths, path);
                findPath(root->right, paths, path);
            }
        }
    }
};