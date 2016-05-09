//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "38_Count_and_Say.cpp"



int main(int argc, const char * argv[]) {

    Solution s;
    ListNode *l1, *l2;
    l1 = new ListNode(1);
    l1->next = new ListNode(5);
    l2 = new ListNode(3);
    l2->next =new ListNode(6);

    s.countAndSay(2);
    
    return 0;
}
