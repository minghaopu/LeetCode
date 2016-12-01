//
//  61.cpp
//  LeetCode
//
//  Created by roneil on 11/30/16.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p = newHead;
        int count = 0;
        while (p->next) {
            count++;
            p = p->next;
        }
        k %= count; // k > count; i.e. k = 99999, count = 3;
        if (k == 0) return head; // k == 0 do nothing
        count -= k;
        ListNode *last = p;
        p = newHead;
        while (count-- > 0) {
            p = p->next;
        }
        newHead->next = p->next;
        p->next = NULL;
        last->next = head;
        return newHead->next;
    }
};
