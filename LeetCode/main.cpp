//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "252_Meeting_Room.cpp"



int main(int argc, const char * argv[]) {

    std::unordered_map<char, int> letter_counts;
    Solution so;
    
    
    Interval a(3,10);
    Interval b(2,4);
    
    vector<Interval> s {a,b};
    so.canAttendMeetings(s);
    
    return 0;
}
