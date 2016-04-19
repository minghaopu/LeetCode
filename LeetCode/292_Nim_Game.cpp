//
//  292_Nim_Game.cpp
//  LeetCode
//
//  Created by roneil on 16/4/19.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    int num;
public:
    Solution (int n) {
        num = n;
    }
    bool canWinNim() {
        return num%4==0?false:true;
    }
};