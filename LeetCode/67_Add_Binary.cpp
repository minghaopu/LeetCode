//
//  67_Add_Binary.cpp
//  LeetCode
//
//  Created by roneil on 16/5/12.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int k = max(i,j)+1;
        string r = "";
        int flag = 0;
        while (k > 0) {
            if (i >= 0) {
                flag += int(a[i]) - 48;
                i--;
            }
            if (j >= 0) {
                flag += int(b[j]) - 48;
                j--;
            }
            r.insert(0,1,flag%2+'0');
            flag = flag > 1?1:0;
            k--;
        }
        if (flag == 1) r.insert(0,1,'1');
        return r;
    }
};