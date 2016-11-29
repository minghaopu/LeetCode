//
//  21_Merge_Two_Sorted_Lists.cpp
//  LeetCode
//
//  Created by roneil on 16/5/7.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ptr = new ListNode(0);
        ListNode *head = ptr;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            }else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if (l1 == NULL) {
            ptr->next = l2;
        }
        else if (l2 == NULL) {
            ptr->next = l1;
        }
        return head->next;
    }
};