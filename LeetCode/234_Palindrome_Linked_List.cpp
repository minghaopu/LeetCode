//
//  234_Palindrome_Linked_List.cpp
//  LeetCode
//
//  Created by roneil on 8/23/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* rev = NULL;
        ListNode* temp = NULL;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            temp = slow->next;
            slow->next = rev;
            rev = slow;
            slow = temp;
        }
        if (fast != NULL) slow = slow->next;
        while (slow != NULL) {
            if (slow->val != rev->val) return false;
            slow = slow->next;
            rev = rev->next;
        }
        return slow == NULL;
    }
};