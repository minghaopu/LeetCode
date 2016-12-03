//
//  148.cpp
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;// fast has to be head->next;
        int count = 0;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *h2 = slow->next;
        slow->next = NULL;
        return mergeList(sortList(head), sortList(h2));
    }
    ListNode* mergeList(ListNode *h1, ListNode *h2) {
        
        ListNode *newHead = new ListNode(0);
        ListNode *p = newHead;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            } else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        if (h1) p->next = h1;
        if (h2) p->next = h2;
        return newHead->next;
    }
};
