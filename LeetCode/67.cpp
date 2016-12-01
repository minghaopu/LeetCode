//
//  67.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) return addBinary(b, a);
        if (b == "") return a;
        int j = (int)b.size() - 1;
        int i = (int)a.size() - 1;
        int carry = 0;
        int tmp;
        while (j >= 0) {
            tmp = (a[i] - '0') + (b[j] - '0') + carry;
            carry = tmp / 2;
            tmp %= 2;
            a[i] = char('0' + tmp);
            i--;
            j--;
        }
        
        
        while (i >= 0) {
            tmp = (a[i] - '0') + carry;
            carry = tmp / 2;
            tmp %= 2;
            a[i] = char('0' + tmp);
            i--;
        }
        if (carry == 0) return a;
        if (i < 0) return "1" + a;
        i = 0;
        while (a[i] == '0') i++; // remove the head 000011100
        return a.substr(i);
    }
};
