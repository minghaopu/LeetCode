//
//  82_83.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = head, *p = head;
        while (pre) {
            if (p == NULL || p->val != pre->val) {
                pre->next = p;
                pre = p;
            } else {
                p = p->next;
            }
        }
        return head;
    }
    ListNode* deleteDuplicates_remain_zero(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p = head, *pre = newHead;
        while (p && p->next) {
            while (p->next && p->next->val == p->val) p = p->next;
            if (pre->next != p) {
                pre->next = p->next;
                p = pre->next;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return newHead->next;
    }
};
