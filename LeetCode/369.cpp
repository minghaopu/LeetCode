//
//  369.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
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
    ListNode* plusOne(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = NULL, *p = newHead, *next;
        while (p) {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        
        p = pre;
        int carry = 1, tmp = 0;
        while (carry) {
            tmp = p->val + carry;
            carry = tmp / 10;
            p->val = tmp % 10;
            p = p->next;
        }
        p = pre;
        pre = NULL;
        while (p) {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return newHead->val == 0 ? newHead->next : newHead;
    }
};
