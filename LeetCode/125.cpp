//
//  125.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = (int) s.length() - 1;
        while (left < right) {
            while (!isalnum(s[left]) && left < right) left++;
            while (!isalnum(s[right]) && left < right) right--;
            if (toupper(s[left++]) != toupper(s[right--])) return false;
        }
        return true;
    }
};
