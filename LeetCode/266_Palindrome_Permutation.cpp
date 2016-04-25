//
//  266_Palindrome_Permutation.cpp
//  LeetCode
//
//  Created by roneil on 16/4/24.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    Solution () {};
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> map;
        for (int index = 0; index<s.length(); index++) {
            char t = s[index];
            map[t] = map[t]+1;
        }
        bool hasOdd = false;
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second%2 != 0) {
                if (hasOdd) {
                    return false;
                }else{
                    hasOdd = true;
                }
            };
        }
        return true;
    }
};
