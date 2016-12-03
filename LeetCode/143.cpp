//
//  143.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
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
    void reorderList(ListNode* head) {
        // if (!head) return;
        ListNode *slow = head, *fast = head, *pre = NULL, *next;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == fast) return;
        
        // adjust to half
        if (fast) {
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        // reverse half
        pre = NULL;
        while (slow->next) {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        slow->next = pre;
        
        // insert
        pre = head;
        while (slow) {
            next = slow->next;
            slow->next = pre->next;
            pre->next = slow;
            pre = slow->next;
            slow = next;
        }
    }
};
