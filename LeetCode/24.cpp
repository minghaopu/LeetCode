//
//  24.cpp
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead, *p = head, *next;
        while (p && p->next) {
            next = p->next;
            pre->next = next;
            p->next = next->next;
            next->next = p;
            pre = p;
            p = p->next;
        }
        return newHead->next;
        
    }
};
