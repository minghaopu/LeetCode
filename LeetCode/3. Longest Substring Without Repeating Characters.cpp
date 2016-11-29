//
//  3. Longest Substring Without Repeating Characters.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/29.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cache[128] = {0};
        int start = 0, length = 0;
        for (int i = 0; i < s.length(); i++) {
            cache[s[i]]++;
            
            while (cache[s[i]] > 1) {
                cache[s[start++]]--;
            }
            length = max(i - start + 1, length);
        }
        return max(length, int(s.length()) - start);
    }
};
