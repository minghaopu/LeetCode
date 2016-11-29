//
//  38_Count_and_Say.cpp
//  LeetCode
//
//  Created by roneil on 16/5/8.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string result = "1";
        for (int i = 2; i <= n; i++) {
            result = convert(result);
        }
        return result;
    }
    
    string convert(string str) {
        string r = "";
        int count = 1;
        int l = str.length();
        for (int i = 0; i < l; i++) {
            if (i == l-1) {
                r.push_back(count+'0'); // faster than to_string()
                r.push_back(str[i]);
                return r;
            }
            if (str[i] == str[i+1]) {
                count++;
            } else {
                r.push_back(count+'0');
                r.push_back(str[i]);
                count = 1;
            }
        }
        return r;
    }
};