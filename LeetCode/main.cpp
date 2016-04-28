//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "249_Group_Shifted_Strings.cpp"



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
    
    vector<string> ss {"az", "ba", "a", "z"};
    string s = "abcc";
    vector<vector<string>> sg = so.groupStrings(ss);
//    
    return 0;
}
