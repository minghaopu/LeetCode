//
//  299_Bulls_and_Cows.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    string guess;
    string secret;
public:
    Solution (string s1, string s2) {
        secret = s1;
        guess = s2;
    }
    string getHint() {
        int len = int(secret.length());
        int *numsA = new int[10],
            *numsB = new int[10];
        int A = 0, B = 0;
//        numsA.resize(10);
//        numsB.resize(10);
        int index;
        string result = "";
        for (index = 0; index < 10; index++) {
            numsA[index] = 0;
            numsB[index] = 0;
        }
        for (index = 0; index < len; index++) {
            int n1 = int(secret[index])-48;
            int n2 = int(guess[index])-48;
            if (n1 == n2) {
                A++;
            }else{
                numsA[n1] = numsA[n1]+1;
                numsB[n2] = numsB[n2]+1;
            }
        }
        for (index = 0; index < 10; index++) {
            B += min(numsA[index], numsB[index]);
        }
        result = to_string(A)+"A"+to_string(B)+"B";
        return result;
    }
};
