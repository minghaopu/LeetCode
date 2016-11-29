//
//  160_Intersection_of_Two_Linked_List.cpp
//  LeetCode
//
//  Created by roneil on 16/5/8.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *la = headA, *lb = headB;
        // while(la != NULL || lb != NULL) {
        //     if (la == lb) return la;
        //     if (la == NULL && lb != NULL) la = headB;
        //     else if (la != NULL && lb == NULL) lb = headA;
        //     else{
        //         la = la->next;
        //         lb = lb->next;
        //     }
        // }
        while (la != lb) {
            la = la?la->next:headB;
            lb = lb?lb->next:headA;
        }
        return la;
    }
    
};