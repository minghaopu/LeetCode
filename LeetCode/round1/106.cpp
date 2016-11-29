//
//  106.cpp
//  LeetCode
//
//  Created by roneil on 11/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_map<int, int> cache;
    vector<int> in;
    vector<int> post;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        int size = int(inorder.size());
        for (int i = 0; i < size; i++) {
            cache[inorder[i]] = i;
        }
        return buildSubTree(0, size - 1, 0, size - 1);
    }
    TreeNode* buildSubTree(int istart, int iend, int pstart, int pend) {
        if (pstart > pend || istart > iend) return NULL;
        int rootVal = post[pend];
        TreeNode* root = new TreeNode(rootVal);
        int iroot = cache[rootVal];
        root->right = buildSubTree(iroot, iend, pend - (iend - iroot), pend - 1);
        root->left = buildSubTree(istart, iroot - 1, pstart, pend - (iend - iroot) - 1);
        return root;
    }
    
};
