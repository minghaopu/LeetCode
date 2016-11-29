//
//  405. Convert a Number to Hexadecimal.cpp
//  LeetCode
//
//  Created by roneil on 11/19/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
string toHex(int num) {
    if (num == 0) return "0";
    int count = 0;
    string s = "";
    while (num != 0 && count < 8) {
        int mod = num & 15;
        if (mod < 10) s += '0' + mod;
        else s += 'a' + mod - 10;
        num >>= 4;
        count++;
    }
    reverse(s.begin(), s.end());
    return s;
}
string toHex2(int num) {
    if (num == 0) return "0";
    vector<char> map = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'a', 'b', 'c', 'd', 'e', 'f'};
    if (num > 0) {
        string s = "";
        int tmp = num;
        while (tmp != 0) {
            int mod = tmp % 16;
            tmp /= 16;
            s += map[mod];
        }
        if (s.back() == '0') s += '1';
        reverse(s.begin(), s.end());
        return s;
    } else {
        num -= -1;
        num *= -1;
        string s = "ffffffff";
        int i = 7;
        while (num != 0) {
            int mod = num % 16;
            num /= 16;
            if (mod == 0 && num > 0)  {
                if (i == 0) return "0";
                s[i-1] = 'e';
                num--;
                i--;
            } else {
                int t = s[i] - map[mod];
                if (t > 15) t -= 39;
                s[i] = map[t];
                i--;
            }
            
        }
        return s;
    }
}
