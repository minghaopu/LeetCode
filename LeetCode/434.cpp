//
//  434.cpp
//  LeetCode
//
//  Created by neal on 12/16/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int countSegments(string s) {
        // if (s == "") return 0;
        // stringstream ss(s);
        // string token;
        // int count = 0;
        // while (getline(ss, token, ' ')) {
        //     if (token != "") count++;
        // }
        // return count;
        if (s == "") return 0;
        int count = 0;
        bool pre = s[0] != ' ';
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (pre) {
                    count++;
                }
                pre = false;
            } else pre = true;
        }
        if (pre) count++;
        return count;
    }
};
