//
//  203.cpp
//  LeetCode
//
//  Created by roneil on 8/29/16.
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
        if (head == NULL) return head;
        ListNode* psu = new ListNode(0);
        psu->next = head;
        ListNode* cur = psu;
        ListNode* temp;
        while (cur && cur->next) {
            if (cur->next->val == val) {
                temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return psu->next;
    }
};