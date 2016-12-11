//
//  297.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
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
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* front = NULL;
        int size = 0;
        while (!q.empty()) {
            size = q.size();
            while (size--) {
                front = q.front();
                q.pop();
                res += !front ? "null," : to_string(front->val) + ',';
                if (front) {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        stringstream ss (data);
        string token;
        TreeNode *root = NULL, *front = NULL;
        queue<TreeNode*> q;
        int subTreeCount = 0;
        while (getline(ss, token, ',')) {
            if (q.empty()) {
                if (token == "null") return root;
                int val = stoi(token);
                root = new TreeNode(val);
                q.push(root);
            } else {
                
                while (!q.empty() && !q.front()) q.pop();
                if (q.empty()) return root;
                
                front = q.front();
                
                if (subTreeCount == 0) {
                    subTreeCount++;
                    if (token == "null") continue;
                    front->left = new TreeNode(stoi(token));
                    q.push(front->left);
                } else {
                    subTreeCount = 0;
                    q.pop();
                    if (token == "null") continue;
                    front->right = new TreeNode(stoi(token));
                    q.push(front->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
