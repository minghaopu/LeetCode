//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
//#include "Medium.cpp"
//#include "312. Burst Balloons.cpp"
//#include "Hard.cpp"
//#include "421. Maximum XOR of Two Numbers in an Array.cpp"

int main(int argc, const char * argv[]) {
    string word = "ZZZZ";
    int _len = 4;
    int val = 0;
    for (int i = 0; i < _len && i < word.length(); i++) {
        val = val * 26 + (word[i] - 'A' + 1);
    }
    cout<<INT_MIN<<endl;;
    return 0;
}
