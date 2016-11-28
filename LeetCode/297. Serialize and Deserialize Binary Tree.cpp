//
//  297. Serialize and Deserialize Binary Tree.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/24.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
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
class Codec {
private:
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL) return res;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while (!Q.empty()) {
            int count = Q.size();
            for (int i = 0; i < count; i++) {
                TreeNode* p = Q.front();
                Q.pop();
                if (!p) res +="#,";
                else {
                    res += to_string(p->val) + ",";
                    Q.push(p->left);
                    Q.push(p->right);
                }
            }
        }
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { // construct tree from depth traverse
        if (data == "") return NULL;
        queue<TreeNode*> Q;
        TreeNode* root = NULL;
        int i = 0;
        int num = 0;
        int sign = 1;
        int shift = 0;
        bool isPreNull = false;
        while (i < data.length()) {
            if (data[i] == ',') {
                num *= sign;
                if (Q.empty()) {
                    root = new TreeNode(num);
                    Q.push(root);
                } else {
                    TreeNode* p = Q.front();
                    if ((i - shift - 1) % 4 == 0) { // right sub tree
                        if (!isPreNull) {
                            p->right = new TreeNode(num);
                            Q.push(p->right);
                        } else isPreNull = false;
                        Q.pop();
                    } else { // left sub tree
                        if (!isPreNull) {
                            p->left = new TreeNode(num);
                            Q.push(p->left);
                        } else isPreNull = false;
                    }
                }
                num = 0;
                sign = 1;
            } else if (data[i] == '#') {
                isPreNull = true;
            } else if (data[i] == '-') {
                sign = -1;
                shift++;
            } else {
                num = num * 10 + data[i] - '0';
                if (num > 9) shift++;
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
