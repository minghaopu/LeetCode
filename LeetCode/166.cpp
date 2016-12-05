//
//  166.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res = "";
        if (numerator < 0 ^ denominator < 0) res += '-';
        long nn = abs((long)numerator);
        long dd = abs((long)denominator);
        long tmp = nn / dd;
        res += to_string(tmp);
        long mod = nn % dd;
        if (mod == 0) return res;
        res += '.';
        unordered_map<long, int> hash;
        mod *= 10;
        while (mod) {
            if (hash.find(mod) != hash.end()) {
                res.insert(hash[mod], 1, '(');
                res += ')';
                return  res;
            }
            hash[mod] = (int)res.length();
            tmp = mod / dd;
            res += to_string(tmp);
            mod = (mod % dd) * 10;
        }
        return  res;
    }
};
