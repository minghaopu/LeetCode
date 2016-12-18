//
//  382.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
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
    int count;
    vector<int> cache;
public:
    /** @param head The linked list's head.
     Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode *p = head;
        count = 0;
        while (p) {
            cache.push_back(p->val);
            p = p->next;
            count++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return count == 0 ? 0 : cache[rand() % count];
    }
};

class SolutionII {
    int count;
    ListNode* _head;
public:
    /** @param head The linked list's head.
     Note that the head is guaranteed to be not null, so it contains at least one node. */
    SolutionII(ListNode* head) {
        _head = head;
        ListNode *p = head;
        count = 0;
        while (p) {
            p = p->next;
            count++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = rand() % count;
        ListNode *p = _head;
        while (i--) p = p->next;
        return _head ? p->val : 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
