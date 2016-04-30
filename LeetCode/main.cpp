//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "206_Reverse_Linked_List.cpp"



int main(int argc, const char * argv[]) {

//    std::unordered_map<char, int> letter_counts;
    Solution so;
//
//    
//    Interval a(3,10);
//    Interval b(2,4);
//    
//    vector<Interval> s {a,b};
//    so.canAttendMeetings(s);
//

    ListNode * node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    so.reverseList(node);
    return 0;
}
