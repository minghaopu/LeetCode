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
int minCut(string s) {
    int l = (int) s.length();
    int minCuts[l+1];
    iota(minCuts, minCuts+l+1, -1);
    for (int i = 0; i <= l; i++) cout<<minCuts[i]<<endl;
    return 0;
}
int main(int argc, const char * argv[]) {
    minCut("afdsafdsafsa");
    return 0;
}
