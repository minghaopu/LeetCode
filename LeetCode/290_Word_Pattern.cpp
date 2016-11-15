//
//  290_Word_Pattern.cpp
//  LeetCode
//
//  Created by roneil on 16/4/19.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <sstream>
using namespace std;

class Solution {
private:
    string pattern;
    string str;
public:
    Solution (string p, string s) {
        pattern = p;
        str = s;
    }
    bool wordPattern() {
        
        int i = 0;
        int length = int(pattern.length());
        istringstream iss(str);
        string token;
        
        map<char, string> list;
        map<string, char> listR;
        
        while (getline(iss, token, ' ')) {

            if (list.find(pattern[i])==list.end()) {
                if (listR.find(token) != listR.end()) {
                    return false;
                }
                listR[token] = pattern[i];
                list[pattern[i]] = token;
            }else {
                if (list[pattern[i]] != token) {
                    return false;
                }
            }
            i++;
        }
        if (i!=length) {
            return false;
        }
        return true;
    }
};
