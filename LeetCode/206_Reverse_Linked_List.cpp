//
//  206_Reverse_Linked_List.cpp
//  LeetCode
//
//  Created by roneil on 16/4/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"


struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
//        vector<int> stack;
//        while (head != NULL) {
//            stack.push_back(head->val);
//            head = head->next;
//        }
//        ListNode* rh = new ListNode(stack.back());
//        stack.pop_back();
//        ListNode* p = rh;
//        while (stack.size() != 0) {
//            p->next = new ListNode(stack.back());
//            stack.pop_back();
//            p = p->next;
//        }
//        p = NULL;
//        return rh;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};