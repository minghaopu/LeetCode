//
//  141_Linked_List_Cycle.cpp
//  LeetCode
//
//  Created by roneil on 16/5/3.
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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};