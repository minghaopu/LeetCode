 //
//  307.cpp
//  LeetCode
//
//  Created by roneil on 11/16/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class NumArray_TLE {// time limited exceed
private:
    vector<int> sums;
    vector<int> n;
    int size;
public:
    NumArray_TLE(vector<int> &nums) {
        sums = nums;
        n = nums;
        size = nums.size();
        for (int i = 1; i < size; i++) {
            sums[i] += sums[i-1];
        }
    }
    
    void update(int i, int val) {
        int dif;
        if (i == 0) {
            dif = sums[i] - val;
        }
        else dif = sums[i] - sums[i-1] - val;
        for (int j = i; j < size; j++) {
            sums[j] -= dif;
        }
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? sums[j]: sums[j] - sums[i - 1];
    }
};

class NumArray {
private:
    struct SegmentTreeNode {
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int start, int end): start(start), end(end), left(NULL), right(NULL) {};
    };
    SegmentTreeNode* _root;
    SegmentTreeNode* buildTree(vector<int>& nums, int low, int high) {
        if (low > high) return NULL;
        else {
            SegmentTreeNode* node = new SegmentTreeNode(low, high);
            if (low == high) {
                node->sum = nums[low];
            } else {
                int mid = low + (high - low) / 2;
                node->left = buildTree(nums, low, mid);
                node->right = buildTree(nums, mid + 1, high);
                node->sum = node->left->sum + node->right->sum;
            }
            return node;
        }
        
    }
    void update(SegmentTreeNode* node, int position, int val) {
        if (node->start == position && node->end == position) {
            node->sum = val;
            return;
        }
        int mid = node->start + (node->end - node->start) / 2;
        if (position <= mid) update(node->left, position, val);
        else update(node->right, position, val);
        node->sum = node->left->sum + node->right->sum;
    }
    int sumRange(SegmentTreeNode* node, int low, int high) {
        if (node->start == low && node->end == high) {
            return node->sum;
        }
        int mid = node->start + (node->end - node->start) / 2;
        if (high <= mid) {
            return sumRange(node->left, low, high);
        } else if (low > mid) {
            return sumRange(node->right, low, high);
        } else {
            return sumRange(node->left, low, mid) + sumRange(node->right, mid + 1, high);
        }
        
    }
public:
    NumArray(vector<int> &nums) {
        _root = buildTree(nums, 0, int(nums.size() - 1));
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
