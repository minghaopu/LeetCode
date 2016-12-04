//
//  160.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = p ? p->next : headB; // a-a-c-c-b-b-b-c-c
            q = q ? q->next : headA; // b-b-b-c-c-a-a-c-c
        }
        return p;
    }
};
