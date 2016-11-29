//
//  273. Integer to English Words.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/23.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<string> d1;
    vector<string> d2;
    vector<string> base;
public:
    string numberToWords(int num) {
        d1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        d2 = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        base = {"", "Thousand","Million","Billion"};
        if (num == 0) return "Zero";
        string res = "";
        int count = 0;
        while (num != 0) {
            int part = num % 1000;
            num /= 1000;
            if (part != 0) res = hundredToWord(part) + " " + base[count++] + " " + res;
            else count++;
        }
        while (res.back() == ' ') res.pop_back();
        return res;
        
    }
    string hundredToWord(int num) {
        string res = "";
        int mod = num % 100;
        int fac = num / 100;
        if (fac != 0) res = d1[fac] + " " + "Hundred";
        if (mod != 0) res += (fac != 0 ? " ":"") +  (mod < 20 ? d1[mod] : (d2[(mod/10)] + (mod % 10 == 0 ? "" : (" " + d1[mod%10]))));
        return res;
    }
};
