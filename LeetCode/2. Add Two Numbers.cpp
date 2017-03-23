//
//  2. Add Two Numbers.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int carry = 0, val = 0;
        ListNode *p = l1, *q = l2;
        ListNode* newHead = new ListNode(0);
        ListNode* t = newHead;
        while (p || q || carry) {
            if (p && q) {
                val = p->val + q->val + carry;
                p = p->next;
                q = q->next;
            } else if (p) {
                val = p->val + carry;
                p = p->next;
            } else if (q) {
                val = q->val + carry;
                q = q->next;
            } else if (carry) {
                val = carry;
            }
            t->next = new ListNode(val % 10);
            carry = val / 10;
            t = t->next;
        }
        return newHead->next;
    }
};
