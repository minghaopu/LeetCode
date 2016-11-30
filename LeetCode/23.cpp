//
//  23.cpp
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> heap(comp);
        ListNode *newHead = new ListNode(0);
        ListNode *p = newHead;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) heap.push(lists[i]);
        }
        while (!heap.empty()) {
            ListNode* top = heap.top();
            if (top->next) heap.push(top->next);
            heap.pop();
            p->next = top;
            p = p->next;
            p->next = NULL;
        }
        return newHead->next;
    }
};
