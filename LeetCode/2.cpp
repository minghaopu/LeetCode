//
//  2.cpp
//  LeetCode
//
//  Created by roneil on 11/2/16.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(0);
        ListNode* newHead = p;
        int ext = 0;
        int val = 0;
        while (l1 || l2 || ext) {
            newHead->next = new ListNode(0);
            newHead = newHead->next;
            if (l1 && l2) {
                val = l1->val + l2->val + ext;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1) {
                val = l1->val + ext;
                l1 = l1->next;
            }
            else if (l2) {
                val = l2->val + ext;
                l2 = l2->next;
            }
            else val = ext;
            newHead->val = val % 10;
            ext = val/10;
        }
        return p->next;
    }
};