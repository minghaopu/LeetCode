
//
//  246_247_248_Strobogrammatic_Number.cpp
//  LeetCode
//
//  Created by roneil on 11/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    // 246
    bool isStrobogrammatic(string num) {
        int map[10];
        memset(map, -1, sizeof(map));
        map[0] = 0;
        map[1] = 1;
        map[8] = 8;
        map[6] = 9;
        map[9] = 6;
        for (int i = 0, j = num.size() - 1; i <= j; i++, j--) {
            if(map[num[i] - '0'] != num[j] - '0') return false;
        }
        return true;
    }
    
    //247
    vector<string> findStrobogrammatic(int n) {
        if (n < 1) return {};
        return helper(0, n-1);
    }
    vector<string> helper(int start, int end) {
        if (end == start) return {"0" , "1", "8"};
        if (end < start) return {""};
        vector<string> middle = helper(start + 1, end - 1);
        vector<string> res;
        for (int i = 0; i < middle.size(); i++) {
            string s = middle[i];
            if (start != 0) res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("8" + s + "8");
            res.push_back("6" + s + "9");
            res.push_back("9" + s + "6");
        }
        return res;
    }
    
    //248
};
