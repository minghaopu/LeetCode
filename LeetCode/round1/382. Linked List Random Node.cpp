//
//  382. Linked List Random Node.cpp
//  LeetCode
//
//  Created by roneil on 11/21/16.
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
private:
    unordered_map<int, int> cache;
    int total;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode* p = head;
        total = 0;
        while (p) {
            cache[total] = p->val;
            total++;
            p = p->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        int count = rand() % total;
        return cache[count];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
