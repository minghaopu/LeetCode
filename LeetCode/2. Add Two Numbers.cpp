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
        
        ListNode* newHead = new ListNode(0);
        ListNode *p = newHead;
        int carry = 0;
        while (l1 && l2) {
            p->next = new ListNode(l1->val + l2->val + carry);
            if (p->next->val > 9) {
                p->next->val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
            while (l1) {
                p->next = new ListNode(l1->val + carry);
                if (p->next->val > 9) {
                    p->next->val -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                p = p->next;
                l1 = l1->next;
            }
        } else if (l2) {
            while (l2) {
                p->next = new ListNode(l2->val + carry);
                if (p->next->val > 9) {
                    p->next->val -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                p = p->next;
                l2 = l2->next;
            }
        }
        if (carry) p->next = new ListNode(carry);
        return newHead->next;
    }
};
