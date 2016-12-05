//
//  165.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = (int)version1.size(), n2 = (int)version2.size();
        int num1 = 0, num2 = 0;
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') num1 = num1 * 10 + version1[i++] - '0';
            while (j < n2 && version2[j] != '.') num2 = num2 * 10 + version2[j++] - '0';
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};
