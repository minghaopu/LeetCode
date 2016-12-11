//
//  307.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class NumArray {
private:
    struct Node {
        int start;
        int end;
        int sum;
        Node *left, *right;
        Node(int start, int end) : start(start), end(end), left(NULL), right(NULL) {};
    };
    Node* _root;
    Node* buildTree(vector<int>& nums, int low, int high) {
        if (low > high) return NULL;
        else {
            Node* n = new Node(low, high);
            if (low == high) n->sum = nums[low];
            else {
                int mid = low + (high - low) / 2;
                n->left = buildTree(nums, low, mid);
                n->right = buildTree(nums, mid + 1, high);
                n->sum = n->left->sum + n->right->sum;
            }
            return n;
        }
        
    }
    void update(Node* node, int position, int val) {
        if (node->start == position && node->end == position) {
            node->sum = val;
            return;
        }
        int mid = node->start + (node->end - node->start) / 2;
        if (position <= mid) update(node->left, position, val);
        else update(node->right, position, val);
        node->sum = node->left->sum + node->right->sum;
    }
    int sumRange(Node* node, int low, int high) {
        if (node->start == low && node->end == high) return node->sum;
        int mid = node->start + (node->end - node->start) / 2;
        if (high <= mid) return sumRange(node->left, low, high);
        else if (low > mid) return sumRange(node->right, low, high);
        else return sumRange(node->left, low, mid) + sumRange(node->right, mid + 1, high);
    }
public:
    NumArray(vector<int> &nums) {
        _root = buildTree(nums, 0, (int)nums.size() - 1);
    }
    
    void update(int i, int val) {
        update(_root, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(_root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
