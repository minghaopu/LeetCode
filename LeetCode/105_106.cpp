//
//  105_106.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
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
    unordered_map<int, int> cache;
public:
    TreeNode* buildTree_from_preorder_inorder(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return NULL;
        for (int i = 0; i < inorder.size(); i++) cache[inorder[i]] = i;
        return helper(preorder, 0, (int)preorder.size() - 1, 0, (int)preorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, int pstart, int pend, int istart, int iend) {
        if (pstart > pend || istart > iend) return NULL;
        int rootVal = preorder[pstart];
        int iroot = cache[rootVal];
        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(preorder, pstart + 1, pstart + iroot - istart, istart, iroot);
        root->right = helper(preorder, pstart + iroot - istart + 1, pend, iroot + 1, iend);
        return root;
    }
    TreeNode* buildTree_from_postorder_inorder(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty()) return NULL;
        for (int i = 0; i < inorder.size(); i++) cache[inorder[i]] = i;
        return helper2(postorder, 0, (int)inorder.size() - 1, 0, (int)inorder.size() - 1);
    }
    TreeNode* helper2(vector<int>& postorder, int istart, int iend, int pstart, int pend) {
        if (istart > iend || pstart > pend) return NULL;
        int rootVal = postorder[pend];
        int iroot = cache[rootVal];
        TreeNode *root = new TreeNode(rootVal);
        root->right = helper2(postorder, iroot, iend, pend - (iend - iroot), pend - 1);
        root->left = helper2(postorder, istart, iroot-1, pstart, pend - (iend - iroot) - 1);
        return root;
    }
};
