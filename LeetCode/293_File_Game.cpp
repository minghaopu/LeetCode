//
//  293_File_Game.cpp
//  LeetCode
//
//  Created by roneil on 16/4/18.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
private:
    string s;
public:
    Solution (string s1) {
        s = s1;
    }
    vector<string> generatePossibleNextMoves() {
        vector<string> result;
        int length = s.length(), index;
        for (index = 0; index < length-1; index++) {
            if(s[index] == s[index+1] && s[index] == '+') {
                string temp = s;
                temp[index] = '-';
                temp[index+1] = '-';
                result.push_back(temp);
            }
        }
        return result;
    }
};