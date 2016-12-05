//
//  173.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// preorder traverse
class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        findNext(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        if (s.empty()) return 0;
        TreeNode* t = s.top();
        s.pop();
        if (t->right) findNext(t->right);
        return t->val;
    }
    void findNext(TreeNode* root) {
        TreeNode* p = root;
        while (p) {
            s.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
