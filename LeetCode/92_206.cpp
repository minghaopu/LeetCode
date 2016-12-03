//
//  92_206.cpp
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *newHead = new ListNode(0);
        ListNode *next;
        while (head) {
            next = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = next;
        }
        return newHead->next;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n) return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead, *p = head, *next;
        n -= m;
        while (m-- > 1) {
            pre = pre->next;
            p = p->next;
        }
        ListNode *tail = p;
        p = p->next;
        while (n-- > 0 && p) {
            next = p->next;
            p->next = pre->next;
            pre->next = p;
            p = next;
        }
        tail->next = p;
        return newHead->next;
    }
};
