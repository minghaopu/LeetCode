//
//  138.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead = new RandomListNode(0);
        RandomListNode *pre = newHead, *p = head;
        while (p) {
            RandomListNode *copy = new RandomListNode(p->label);
            copy->next = p->next;
            p->next = copy;
            p = copy->next;
        }
        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next; // p->random->next is the copy of p->random
            }
            p = p->next->next;
        }
        p = head;
        while (p) {
            pre->next = p->next;
            p->next = p->next->next;
            pre = pre->next;
            p = p->next;
        }
        return newHead->next;
    }
};
