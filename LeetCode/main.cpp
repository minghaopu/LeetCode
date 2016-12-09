//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//
#include "Header.h"
//#include "79.cpp"
//#include "Medium.cpp"
//#include "312. Burst Balloons.cpp"
//#include "Hard.cpp"
//#include "421. Maximum XOR of Two Numbers in an Array.cpp"
int main(int argc, const char * argv[]) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
        cout<<q.top()<<endl;
    }
    for (int i = 0; i < 10; i++) {
        q.pop();
        cout<<q.top()<<endl;
    }
    return 0;
}
