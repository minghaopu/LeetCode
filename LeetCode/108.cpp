//
//  108.cpp
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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createSubTree(nums, 0, (int)nums.size() - 1);
    }
    TreeNode* createSubTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int index = (start + end + 1) / 2;
        TreeNode *root = new TreeNode(nums[index]);
        root->left = createSubTree(nums, start, index - 1);
        root->right = createSubTree(nums, index + 1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return createSubTree_List(head, NULL);
    }
    TreeNode* createSubTree_List(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;
        if (head->next == tail) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = createSubTree_List(head, slow);
        root->right = createSubTree_List(slow->next, tail);
        return root;
    }
};
