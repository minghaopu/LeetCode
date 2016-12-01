//
//  25.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/30.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k < 2) return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *cur = head, *pre = newHead, *next = NULL, *tmp = NULL;
        int count = 0;
        while (cur) {
            cur = cur->next;
            count++;
        }
        
        while (count >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 1; i < k; i++) {
                tmp = next->next;
                next->next = pre->next;
                pre->next = next;
                cur->next = tmp;
                next = tmp;
            }
            pre = cur;
            count -= k;
        }
        return newHead->next;
    }
};
