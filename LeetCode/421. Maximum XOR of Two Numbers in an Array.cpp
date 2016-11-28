//
//  421. Maximum XOR of Two Numbers in an Array.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/27.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
private:
    struct Node {
        Node* next[2];
        Node() {
            next[0] = NULL;
            next[1] = NULL;
        }
    };
    Node* root;
    void insert(int num) {
        Node* p = root;
        for (int i = 30; i >= 0; i--) {
            int bit = num & (1 << i);
            int flag = bit == 0 ? 0 : 1;
            if (p->next[flag] == NULL) p->next[flag] = new Node();
            p = p->next[flag];
        }
    }
    int search(int num) {
        int res = 0;
        Node* p = root;
        for (int i = 30; i >= 0; i--) {
            int bit = num & (1 << i);
            int flag = bit == 0 ? 0 : 1;
            if (p->next[1 - flag] == NULL) {
                p = p->next[flag];
                res += flag << i;
            } else {
                p = p->next[1-flag];
                res += (1-flag) << i;
            }
        }
        return res;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        root = new Node();
        for (int num : nums) {
            insert(num);
        }
        for (int num : nums) {
            int xorValue = search(num);
            res = max(res, xorValue ^ num);
        }
        return res;
    }
};
