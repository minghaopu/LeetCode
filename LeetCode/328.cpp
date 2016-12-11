//
//  328.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode *fast = head->next, *pre = head;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = pre->next->next;
        }
        
        if (head->next == fast) return head;
        fast = pre; // last odd
        ListNode *tail = fast;
        ListNode *start = head;
        while (start != fast) {
            ListNode *next = start->next->next;
            start->next->next = tail->next;
            tail->next = start->next;
            start->next = next;
            start = next;
            tail = tail->next;
        }
        return head;
    }
};
