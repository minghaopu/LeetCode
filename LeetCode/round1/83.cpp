//
//  83.cpp
//  LeetCode
//
//  Created by roneil on 9/1/16.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head;
        while (pre) {
            if (cur == NULL || cur->val != pre->val) {
                pre->next = cur;
                pre = cur;
            } else {
                cur = cur->next;
            }
            
        }
        return head;
    }
};