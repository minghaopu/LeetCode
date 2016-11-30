//
//  19.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n == 0) return head;
        int count = 0;
        ListNode *p = head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        while (p) {
            count++;
            p = p->next;
        }
        count -= n;
        p = newHead;
        ListNode *next;
        while (count) {
            p = p->next;
            count--;
        }
        next = p->next;
        p->next = next->next;
        delete next;
        return newHead->next;
    }
};
