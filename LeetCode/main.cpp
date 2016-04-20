//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <iostream>
#include "288_Unique_Word_Abbreviation.cpp"



int main(int argc, const char * argv[]) {
    vector<string> a {"dog","dig"};
    
    ValidWordAbbr so(a);
    so.isUnique("dog");
    

    
    return 0;
}
