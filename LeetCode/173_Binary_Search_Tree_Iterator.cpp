//
//  173_Binary_Search_Tree_Iterator.cpp
//  LeetCode
//
//  Created by roneil on 10/13/16.
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
        TreeNode *t = s.top();
        s.pop();
        if (t->right != NULL) findNext(t->right);
        return t->val;
    }
    /** modify the stack */
    void findNext(TreeNode* root) {
        TreeNode* p = root;
        while (p != NULL) {
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
