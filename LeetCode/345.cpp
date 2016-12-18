//
//  345.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    string reverseVowels(string s) {
        int left = 0, right = (int)s.length() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
