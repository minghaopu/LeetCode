//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//
#include "306.cpp"
//#include "79.cpp"
//#include "Medium.cpp"
//#include "312. Burst Balloons.cpp"
//#include "Hard.cpp"
//#include "421. Maximum XOR of Two Numbers in an Array.cpp"
void test(int amount) {

    int *dp = (int*) malloc (amount * sizeof(int));
    memset(dp, amount, sizeof(int) * (amount));
    for (int i = 0; i < amount; i++) cout<<dp[i]<<endl;
}
int main(int argc, const char * argv[]) {
    test(14);
    return 0;
}
