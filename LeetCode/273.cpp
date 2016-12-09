//
//  273.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<string> d1, d2, base;
public:
    string numberToWords(int num) {
        d1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        d2 = {"", "", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        base = {"" , "Thousand", "Million", "Billion"};
        if (num == 0) return "Zero";
        string res = "";
        int count = 0;
        while (num != 0) {
            int hundred = num % 1000;
            num /= 1000;
            if (hundred != 0) res = hundredToWord(hundred) + " " + base[count++] + " " + res;
            else count++;
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
    string hundredToWord(int num) {
        string res = "";
        int mod = num % 100;
        int fac = num / 100;
        if (fac != 0) res += d1[fac] + " Hundred";
        if (mod != 0) res += (fac == 0 ? "" : " ") + (mod < 20 ? d1[mod] : (d2[mod/10] + (mod % 10 == 0 ? "" : " " + d1[mod%10])));
        return res;
    }
};
