//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//
#include "399.cpp"
//#include "79.cpp"
//#include "Medium.cpp"
//#include "312. Burst Balloons.cpp"
//#include "Hard.cpp"
//#include "421. Maximum XOR of Two Numbers in an Array.cpp"
//void test(int amount) {
//
//    int *dp = (int*) malloc (amount * sizeof(int));
//    memset(dp, amount, sizeof(int) * (amount));
//    for (int i = 0; i < amount; i++) cout<<dp[i]<<endl;
//}
int main(int argc, const char * argv[]) {
    vector<pair<string, string>> a = {{"a","b"},{"b","c"}};
    vector<double> b = {0.0,3.0};
    vector<pair<string, string>> d = {{"b","a"},{"b","c"},{"a","e"},{"a","a"},{"x","x"}};
    Solution s;
    s.calcEquation(a, b, d);
    return 0;
}
