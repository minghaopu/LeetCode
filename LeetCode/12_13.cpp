//
//  12_13.cpp
//  LeetCode
//
//  Created by roneil on 11/29/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string intToRoman(int num) {
        string map[4][10] = {
            {"","I","II","III","IV","V", "VI", "VII", "VIII", "IX"},
            {"","X","XX","XXX","XL","L", "LX", "LXX", "LXXX", "XC"},
            {"","C","CC","CCC","CD","D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        return map[3][num/1000] + map[2][(num%1000)/100] + map[1][((num%100)/10)] + map[0][num%10];
    }
    int romanToInt(string s) {
        unordered_map<char, int> cache;
        cache['M'] = 1000;
        cache['C'] = 100;
        cache['D'] = 500;
        cache['L'] = 50;
        cache['X'] = 10;
        cache['I'] = 1;
        cache['V'] = 5;
        int pre = INT_MAX;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int val = cache[s[i]];
            if (pre < val) num = num - pre + val - pre;
            else num += val;
            pre = cache[s[i]];
        }
        return num;
    }
};
