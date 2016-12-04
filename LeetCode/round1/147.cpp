//
//  147.cpp
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode *newHead = new ListNode(INT_MIN);
        ListNode *p = newHead, *cur = head->next, *q = head;
        p->next = head;
        head->next = NULL;
        while (cur) {
            if (cur->val < q->val) {
                while (cur->val > p->next->val) p = p->next;
                ListNode *next = cur->next;
                cur->next = p->next;
                p->next = cur;
                p = newHead;
                cur = next;
            } else {
                q->next = cur;
                cur = cur->next;
                q = q->next;
                q->next = NULL;
            }
        }
        return newHead->next;
        
    }
};
