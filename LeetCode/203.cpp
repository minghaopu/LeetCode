//
//  203.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode *newHead = new ListNode(0);
        ListNode *pre = newHead, *p = head;
        newHead->next = head;
        while (p) {
            if (p->val == val) {
                pre->next = p->next;
                p->next = NULL;
                p = pre->next;
            } else {
                p = p->next;
                pre = pre->next;
            }
        }
        return newHead->next;
    }
};
