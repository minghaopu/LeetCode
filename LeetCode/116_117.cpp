//
//  116_117.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *pre = root, *cur = NULL;
        while (pre->left) {
            cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
    void connect_II(TreeLinkNode *root) {
        TreeLinkNode *cur = root, *head = NULL, *tail = NULL;
        while (cur) {
            if (cur->left) {
                if (tail) {
                    tail->next = cur->left;
                    tail = tail->next;
                } else head = tail = cur->left;
            }
            if (cur->right) {
                if (tail) {
                    tail->next = cur->right;
                    tail = tail->next;
                } else head = tail = cur->right;
            }
            cur = cur->next;
            if (!cur) {
                cur = head;
                head = tail = NULL;
            }
        }
    }
};
